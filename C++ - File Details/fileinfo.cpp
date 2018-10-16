
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<pwd.h>
using namespace std;

void display(time_t t);

int main() {
	struct stat statBuf;
	struct passwd *pass;
	char fn[30];
	cout << "\nEnter file name:";
	cin >> fn;
	if (stat(fn, &statBuf) < 0) {
		cout << "\nAccess Denied....!!!";
		exit(1);
	}
	cout << "\nOwner ID:" << statBuf.st_uid;
	pass = getpwuid(statBuf.st_uid);
	cout << "\nName:" << pass->pw_name;
	cout << "\nMode:" << hex << statBuf.st_mode;
	cout << "\nAccess Permission:";
	if (statBuf.st_mode & 0x0100)
		cout << "r";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0080)
		cout << "w";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0040)
		cout << "x";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0020)
		cout << "r";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0010)
		cout << "w";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0008)
		cout << "x";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0004)
		cout << "r";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0002)
		cout << "w";
	else
		cout << "_ ";

	if (statBuf.st_mode & 0x0001)
		cout << "x";
	else
		cout << "_ ";

	cout << "\nAcess Time:";
	display(statBuf.st_atime);      //file access time
	cout << "\nInode Modification:";
	display(statBuf.st_ctime);      //inode modification time
	cout << "\nLast Modified:";       //file modification time
	display(statBuf.st_mtime);
	return 0;
}

void display(time_t t) {
	cout << ctime(&t);
	/*struct tm *tp=localtime(&t);
	 cout<<tp->tm_hour;
	 cout<<":"<<tp->tm_min;
	 cout<<":"<<tp->tm_sec;
	 cout<<"\t"<<tp->tm_mday;
	 cout<<" "<<tp->tm_mon;
	 cout<<" "<<tp->tm_year+1900<<"\n";*/

}
