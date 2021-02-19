// CSN-502 - Advanced Operating Systems
// Tutorial 05
// September 30, 2020

// Gourav Siddhad
// 20911004 - g_siddhad@cs.iitr.ac.in
// October 16, 2020

#include "event.hpp"
#include <fstream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;
int nsize = 0;
int last = -1;

vector<string> split(const string& s) {
    vector<string> ret;
    int i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            ++i;

        int j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

string concat_str(vector<string> strs) {
    string final = "";
    for (int i=2; i<strs.size(); i++)
        final = final + " " + strs[i];
    return final;
}

bool iequals(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(), b.begin(), [](char a, char b) {return tolower(a) == tolower(b);});
}

Event get_event(vector<string> tokens, queue<Event> mqueue[], string pname[]) {
    Event e;

    string first = tokens[0];
    std::transform(first.begin(), first.end(), first.begin(), [](unsigned char c) {return std::tolower(c);});

    if (first.compare("begin") == 0) {
        if (pname[nsize].compare("") == 0)
            pname[nsize] = tokens[2];
        else {
            e.set_name("INPERR");
            return e;
        }
    } else if (first.compare("send") == 0){
        e.set_name(pname[nsize]);
        e.set_type("SEND");
        string process = tokens[1];
        std::transform(process.begin(), process.end(), process.begin(), [](unsigned char c) {return std::toupper(c);});
        e.set_tf(process);
        e.set_msg(concat_str(tokens));
        mqueue[nsize].push(e);
    } else if (first.compare("print") == 0){
        e.set_name(pname[nsize]);
        e.set_type("PRINT");
        e.set_msg(tokens[1]);
        mqueue[nsize].push(e);
    } else if (first.compare("recv") == 0) {
        e.set_name(pname[nsize]);
        e.set_type("RECEIVE");
        string process = tokens[1];
        std::transform(process.begin(), process.end(), process.begin(), [](unsigned char c) {return std::toupper(c);});
        e.set_tf(process);
        e.set_msg(concat_str(tokens));
        mqueue[nsize].push(e);
    } else if (first.compare("end") == 0) {
        if (tokens.size() > 2 && iequals(pname[nsize], tokens[2]))
            nsize++;
        else if (tokens.size() == 2)
            nsize++;
        else {
            e.set_name("INPERR");
            return e;
        }
    }
    return e;
}

void print_queues(queue<Event> mqueue[], string pname[], int nsize) {
    for (int i=0; i<nsize; i++) {
        cout << "Process : " << pname[i];
        while(!mqueue[i].empty()) {
            cout << endl;
            mqueue[i].front().print(nsize);
            mqueue[i].pop();
        }
        cout << endl << endl;
    }
}

void print_sequence(vector<Event> sequence) {
    
    cout << setfill (' ');
    cout << setw(5) << "NAME";
    cout << setw(10) << "OPR";
    cout << setw(8) << "MSG";
    cout << setw(10) << "TO/FROM";
    cout << setw(8) << "TIME";
    cout << endl << endl;

    for (int i=0; i<sequence.size(); i++) {
        sequence[i].print(nsize);
        cout << endl;
    }
}

int get_process_no(string pn, string pname[]) {
    for (int i=0; i<nsize; i++) {
        if (iequals(pn, pname[i]))
            return i;
    }
}

Event allocate_time(queue<Event> mqueue[], string pname[], vector<Event> &deadlock) {

    vector<Event> pool;
    vector<Event> sequence;

    int ctime[10][10];
    bool flag = true;

    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            ctime[i][j] = 0;

    while(flag) {
        int laststat = sequence.size();

        for (int i=0; i<nsize; i++) {
            if (mqueue[i].empty())
                continue;
            Event e = mqueue[i].front();
            mqueue[i].pop();

            bool curflag = false;

            if (e.get_type().compare("PRINT") == 0) {
                for (int j=0; j<deadlock.size(); j++) {
                    if (deadlock[j].get_name().compare(e.get_name()) == 0)
                        curflag = true;
                }
                if (!curflag) {
                    ctime[i][i]++;
                    e.set_time(ctime[i]);
                    sequence.push_back(e);
                }
            } else if (e.get_type().compare("SEND") == 0) {
                for (int j=0; j<deadlock.size(); j++)
                    if (deadlock[j].get_name().compare(e.get_name()) == 0)
                        curflag = true;

                if (!curflag) {
                    ctime[i][i]++;
                    e.set_time(ctime[i]);
                    sequence.push_back(e);
                    pool.push_back(e);
                }
            } else if (e.get_type().compare("RECEIVE") == 0) {
                string proname = e.get_name();
                for (int j=0; j<pool.size(); j++)
                    if (iequals(proname, pool[j].get_tf())) {
                        ctime[i][i]++;
                        for (int k=0; k<10; k++)
                            ctime[i][k] = max(ctime[j][k], ctime[i][k]);
                        e.set_time(ctime[i]);
                        sequence.push_back(e);
                        curflag = true;
                        pool.erase(pool.begin() + j);
                    }

                if (!curflag) {
                    e.set_time(ctime[i]);
                    deadlock.push_back(e);
                }
            }
        }

        if (deadlock.size() > 0 && pool.size() > 0)
            for (int k=0; k<deadlock.size(); k++)
                for (int l=0; l<pool.size(); l++)
                    if (iequals(deadlock[k].get_tf(), pool[l].get_name())) {
                        Event e = deadlock[k];
                        // int *loc = e.get_time();
                        int loc1 = get_process_no(e.get_name(), pname);
                        int loc2 = get_process_no(pool[l].get_name(), pname);
                        ctime[loc1][loc1]++;
                        for (int m=0; m<10; m++)
                            ctime[loc1][m] = max(ctime[loc2][m], ctime[loc1][m]);
                        e.set_time(ctime[loc1]);
                        sequence.push_back(e);
                        pool.erase(pool.begin() + l);
                    }

        flag = false;
        for (int i=0; i<nsize; i++) {
            if (mqueue[i].size() > 0)
                flag = true;
        }

        if (laststat == sequence.size() && pool.size()>0) {
            print_sequence(sequence);
            Event e;
            e.set_name("DEADLOCK");
            return e;
        }
    }
    print_sequence(sequence);

    Event e;
    e.set_name("SUCCESS");
    return e;
}

int main() {
    bool exception = false;
    string iline;
    queue<Event> mqueue[10];
    string pname[10];
    vector<Event> deadlock;

    for (int i=0; i<10; i++)
        pname[i] = "";

    ifstream MyReadFile("input.txt");
    while (getline (MyReadFile, iline)) {
        if (nsize >= 10) {
            cout << " Error in Input. Number of processes cannot exceed 10.";
            exception = true;
            break;
        }
        vector<string> tokens;

        if (iline == "") {
            continue;
        } else {
            removeSpaces(iline);
            tokens = split(iline); 
        }

        Event e = get_event(tokens, mqueue, pname);

        if (e.get_name().compare("INPERR") == 0) {
            cout << " Error in Input. Incorrect Sequence of Operations.";
            exception = true;
            break;
        }
    }
    MyReadFile.close();

    Event e;
    if (!exception) {
        cout << endl;
        e = allocate_time(mqueue, pname, deadlock);
        cout << endl;
    }

    if (e.get_name().compare("DEADLOCK") == 0) {
        cout << setfill (' ') << setw(29) << " System Deadlocked." << endl << endl;

        cout << setfill (' ') << setw(18) << "PROCESS" << setw(10) << "TIME" << endl;

        for (int i=0; i<deadlock.size(); i++) {
            cout << setfill (' ') << setw(15) << deadlock[i].get_name() << setw(10) << "( " ;
            int *tt = deadlock[i].get_time();
            for (int j=0; j<nsize; j++)
                cout << tt[j] <<" ";
            cout << ")";
        }
    }

    cout << endl << endl;
}