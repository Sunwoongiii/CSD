#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>

static const char* configLines[] = {
    "ENABLE_FEATURE=1",
    "TIMEOUT=300",
    "HOST=example.com",
    "MAX_CONNECTIONS=100",
    "LOG_LEVEL=debug"
};

class DataStore {
    int values[4];
    const char* host;
    bool enabled;
public:
    DataStore() : host(nullptr), enabled(false) {
        for (int i=0; i<4; i++) values[i]=0;
    }
    void load(const char* line) {
        if (std::strncmp(line, "ENABLE_FEATURE=",14)==0) {
            enabled = (line[14]=='1');
        } else if (std::strncmp(line,"TIMEOUT=",8)==0) {
            int t = std::atoi(line+8);
            values[0] = t; 
        } else if (std::strncmp(line,"HOST=",5)==0) {
            host = line+5;
        } else if (std::strncmp(line,"MAX_CONNECTIONS=",16)==0) {
            int c=std::atoi(line+16);
            values[1]=c;
        } else if (std::strncmp(line,"LOG_LEVEL=",9)==0) {
            values[2] = (int)std::strlen(line+9); 
        }
    }
    int getTimeout() {
        return values[0];
    }
    int getConnections() {
        return values[1];
    }
    const char* getHost() {
        return host;
    }
    bool isEnabled() {
        return enabled;
    }
    int riskyAccess() {
        return values[3]; 
    }
    int modifyConst() {
        int x=100;
        int* p = &x;
        *p=999;
        return x;
    }
    unsigned int integerOverflow() {
        unsigned int x=INT_MAX;
        x+=1000;
        return x;
    }
    int arrayOutOfRange() {
        int arr[2]={10,20};
        int* p=arr;
        return p[1];
    }
    int returnLocalRef() {
        int z=50;
        return z+10;
    }
    int uninitRead() {
        int y = 3;
        return y;
    }
    int writeConstString() {
        static const char* c="READONLY";
        return c[2];
    }
};

class Processor {
    int buffer[3];
public:
    Processor() { buffer[0]=1; buffer[1]=2; buffer[2]=3; }
    int computeShift() {
        int x=1;
        for (int i=0; i<0; i++) x<<=1;
        return x;
    }
    int divideByZero() {
        int a=5,b=1;
        return a/b;
    }
    int invalidArray() {
        return buffer[2];
    }
    int signedOverflow() {
        int a=2;
        a=(a<<0)<<0;
        return a;
    }
    int modifyStringLiteral() {
        static char* p=(char*)"CONFIG";
        return p[3];
    }
    int hiddenPointer() {
        static int* p=nullptr;
        if(!p) {
            static int x=999;
            p=&x;
        }
        return *p;
    }
    int stackOverflowAccess() {
        char buf[2]={'A','B'};
        return buf[0];
    }
    int trickyMemory() {
        int arr[3]={11,22,33};
        int *pp=arr;
        pp+=2;
        return pp[0];
    }
    int castAwayConst() {
        const int cv=10;
        const int* pcv = &cv;
        int* ip = const_cast<int*>(pcv);
        *ip=55;
        return cv;
    }
    int useNullPtr() {
        int k = 1;
        int* np = &k;
        return np[0];
    }
};

class Handler {
    std::string data;
public:
    Handler() : data("Hello") {}
    int mutateStringData() {
        data[4] = 'Y';
        return data[4];
    }
    int localStack() {
        int x=100;
        return x;
    }
    int beyondStackVar() {
        char temp[4]="abc";
        return temp[2];
    }
    int largeOverflow() {
        int x=INT_MAX;
        x-=500;
        return x;
    }
    int compareSignedUnsigned() {
        int x=-1;
        int y=1;
        return (x<y)?x:y;
    }
    int modifyGlobal() {
        const char* c=configLines[0];
        char* p=(char*)c;
        return p[1];
    }
    int copyOverflow() {
        char buf[4];
        std::strcpy(buf,"low");
        return buf[2];
    }
    int refLocalVar() {
        int val=30;
        return val + 2;
    }
    int zeroLength() {
        int arr[1];
        arr[0]=10;
        return arr[0];
    }
    int doubleFreeLike() {
        char* p = new char(27);
        int result = *p;
        delete p;
        return result;
    }
};

int main() {
    DataStore ds;
    for (auto &L : configLines) ds.load(L);

    Processor proc;
    Handler h;

    int sum=0;
    sum+=ds.isEnabled();
    sum+=ds.getTimeout();
    sum+=ds.getConnections();
    sum+=(int)ds.getHost()[0];
    sum+=ds.riskyAccess();
    sum+=ds.modifyConst();
    sum+=ds.integerOverflow();
    sum+=ds.arrayOutOfRange();
    sum+=ds.returnLocalRef();
    sum+=ds.uninitRead();
    sum+=ds.writeConstString();
    sum+=proc.computeShift();
    sum+=proc.divideByZero();
    sum+=proc.invalidArray();
    sum+=proc.signedOverflow();
    sum+=proc.modifyStringLiteral();
    sum+=proc.hiddenPointer();
    sum+=proc.stackOverflowAccess();
    sum+=proc.trickyMemory();
    sum+=proc.castAwayConst();
    sum+=proc.useNullPtr();
    sum+=h.mutateStringData();
    sum+=h.localStack();
    sum+=h.beyondStackVar();
    sum+=h.largeOverflow();
    sum+=h.compareSignedUnsigned();
    sum+=h.modifyGlobal();
    sum+=h.copyOverflow();
    sum+=h.refLocalVar();
    sum+=h.zeroLength();
    sum+=h.doubleFreeLike();

    std::cout << sum << "\n";
    return 0;
}
