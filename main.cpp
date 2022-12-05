#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct Node{
    char key[100];
    struct Node *LSon,*RSon;
    int s1,s2,s3;
};
struct Node *MakeNode(char *b,int NStudent){
    struct Node *tmp=(struct Node *)malloc(sizeof(struct Node));
    strcpy(tmp->key,b);
    tmp->RSon= nullptr;
    tmp->LSon= nullptr;
    tmp->s1=0;
    tmp->s2=0;
    tmp->s3=0;
    if (NStudent==0)
        tmp->s1=1;
    else if(NStudent==1)
        tmp->s2=1;
    else if(NStudent==2)
        tmp->s3=1;
    return tmp;
}
struct Node *insert(struct Node *x,char *b,int NStudent){
    if (x==nullptr)
        return MakeNode(b,NStudent);
    else if (strcmp(b,x->key)>0)
        x->LSon=insert(x->LSon,b,NStudent);
    else if (strcmp(b,x->key)<0)
        x->RSon=insert(x->RSon,b,NStudent);
    else if (strcmp(x->key,b)==0){
        if (NStudent==0)
            x->s1=1;
        else if(NStudent==1)
            x->s2=1;
        else if(NStudent==2)
            x->s3=1;
    }
    return x;
}
int student1=0,student2=0,student3=0;
void traversal(struct Node *root){
    if (root!=nullptr){
        traversal(root->LSon);
        traversal(root->RSon);
        if (root->s1+root->s2+root->s3==1){
            if (root->s1==1){
                student1+=3;
            }
            else if (root->s2==1){
                student2+=3;
            }
            else
                student3+=3;
        }
        else if (root->s1 + root->s2+root->s3==2){
            if (root->s1==1 and root->s2==1){
                student1++;
                student2++;
            }
            else if(root->s1==1 and root->s3==1){
                student1++;
                student3++;
            }
            else if(root->s3==1 and root->s2==1){
                student2++;
                student3++;
            }
        }
    }
}
int main() {
    int n;
    char a[10000];
    cin>>n;
    struct Node *root= nullptr;
    for (int i=0;i<3;i++){
        for (int j=0;j<n;j++){
            cin>>a;
            root=insert(root,a,i);
        }
    }
    traversal(root);
    cout<<student1<<" "<<student2<<" "<<student3;
    return 0;
}
