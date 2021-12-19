#include<windows.h>
#include<ctime>
using namespace std;
int main(){
    int x=GetSystemMetrics(SM_CXSCREEN),y=GetSystemMetrics(SM_CYSCREEN);
    srand(time(0));
    while(1) SetCursorPos(rand()%x,rand()%y);
}
