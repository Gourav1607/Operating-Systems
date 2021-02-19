/* 
 * event.hpp
 * Gourav Siddhad
 * October 16, 2020
 */

#ifndef EVENT_HPP
#define	EVENT_HPP

#include <iostream>
#include <iomanip>
using namespace std;

class Event{
public:
    string name;
    string type;
    string msg;
    string tf_proc;
    int time[10];

    Event() {
        name = "";
        type = "";
        msg = "";
        tf_proc = "";
        for (int i=0;i <10; i++)
            time[i] = 0;

    }

    // Event(string type, string msg, string tf_proc="", int time=0) {
    //     type = "";
    //     msg = "";
    //     tf_proc = "";
    //     time = 0;
    // }

    string get_name() {
        return name;
    }
    string get_type() {
        return type;
    }
    string get_msg() {
        return msg;
    }
    string get_tf() {
        return tf_proc;
    }
    int* get_time() {
        return time;
    }

    void set_name(string name) {
        this->name = name;
    }
    void set_type(string type) {
        this->type = type;
    }
    void set_msg(string msg) {
        this->msg = msg;
    }
    void set_tf(string tf_proc) {
        this->tf_proc = tf_proc;
    }
    void set_time(int time[]) {
        for (int i=0; i<10; i++)
            this->time[i] = time[i];
    }
    void set_time(int j, int time) {
        this->time[j] = time;
    }
    void print(int n) {
        cout << setfill (' ');
        cout << setw(5) << name;
        cout << setw(10) << type;
        cout << setw(8) << msg;
        cout << setw(8) << tf_proc;
        cout << setw(6) << "( ";
        for (int i=0; i<n; i++)
            cout << time[i] <<" ";
        cout << ")";
    }
};

void removeSpaces(string &str) { 
    int n = str.length(); 
    int i = 0, j = -1; 
    bool spaceFound = false; 
  
    while (++j < n && str[j] == ' '); 

    while (j < n) {
        if (str[j] != ' ') {
            if ((str[j] == '.' || str[j] == ',' || 
                 str[j] == '?') && i - 1 >= 0 && 
                 str[i - 1] == ' ') 
                str[i - 1] = str[j++];
            else
                str[i++] = str[j++];
            spaceFound = false; 
        } else if (str[j++] == ' ') { 
            if (!spaceFound) { 
                str[i++] = ' '; 
                spaceFound = true; 
            } 
        } 
    } 

    str.erase(str.begin() + i, str.end()); 
} 

#endif	/* EVENT_HPP */