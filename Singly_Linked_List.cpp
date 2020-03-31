#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1, tot=0;

struct node
{
    node *next;
    int roll;
};

node *root = NULL;

void appendLast(int r)
{
    node *curr = root;
    if(curr == NULL){
        root = new node();
        root->roll = r;
        root->next = NULL;
        tot++;
    }
    else{
        while(curr->next!=NULL){
            curr = curr->next;
        }
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = NULL;
        curr->next = newNode;
        tot++;
    }

}

void appendAhead(int r)
{
    node *curr = root, *prev = NULL;
    if(root == NULL){
        appendLast(r);
        return;
    }

    node *newNode = new node();
    newNode->roll = r;
    newNode->next = curr;
    root = newNode;
    tot++;
}

void appendAt(int r, int pos)
{
    if((pos-1>tot) || (pos-1)<0){
        cout << "Invalid Position.\n";
        return;
    }
    if(root == NULL){
        appendLast(r);
        return;
    }
    node *curr = root, *prev = NULL;
    if(pos == 1){
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = curr;
        root = newNode;
        tot++;
    }
    else{
        --pos;
        while(pos--){
            prev = curr;
            curr = curr->next;
        }
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = curr;
        prev->next = newNode;
        tot++;
    }

}

void print()
{
    node *curr = root;
    if(curr == NULL){
        cout << "No Elements.\n";
        return;
    }
    while(curr!=NULL){
        cout << curr->roll << " ";
        curr = curr->next;
    }
}

void deleteAt(int pos)
{
    if(root == NULL){
        cout << "No Elements.\n";
        return;
    }
    if((pos-1>tot) || (pos-1)<0){
        cout << "Invalid Position.\n";
        return;
    }
    node *curr = root, *prev = NULL;
    if(pos == 1){
        tot--;
        root = root->next;
        delete(curr);
        return;
    }

    --pos;
    while(pos--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete(curr);
    tot--;

}

void deleteAhead()
{
    if(root == NULL){
        cout << "No Elements.\n";
        return;
    }
    node *curr = root;
    root = root->next;
    delete(curr);
    tot--;

}

void deleteLast()
{
    if(root == NULL){
        cout << "No Elements.\n";
        return;
    }
    node *curr = root, *prev = NULL;
    while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete(curr);
    tot--;
}

void solve(int kk)
{
    appendAt(12,1);
    appendAt(13,2);
    appendAhead(13);
    appendLast(100);
    appendAhead(101);
    appendAt(1,3);
    appendAt(11,3);
    appendAt(14,8);
    deleteAt(4);
    deleteAt(6);
    deleteLast();
    deleteAhead();
    print();
    //cout << "Total is: " << tot << "\n";

}

int main()
{
   fast;
   int kk=0;
   //cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}

