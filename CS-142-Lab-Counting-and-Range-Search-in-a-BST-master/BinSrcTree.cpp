#include<iostream>
using namespace std;

//1711103
//RAHUL KUMAR



//A basic node structure for the binary search tree
class node
{
   public:
   int data;
   node *parent,*left,*right;
   node()
   {
      parent=NULL;
      left=NULL;
      right=NULL;
      data=0;
   }
};


//The class for the binaery search tree
class bsTree
{
   public:
   node* root=NULL;
   
   //variables required for size calculations
   int bstsize, leaf, internal,rsrc;
   bsTree()
   {
     //initialising them to zero
     //to avoid warning of non-static data member
     bstsize=0;
     leaf=0;
     internal=0;
     rsrc=0;
   }
   
   
//recursive function to insert the data according to binary search tree data type
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
void insert(node* v, int data)
{ 
   node* temp=new node;
   temp->data=data;
   //empty BST condition
   if(root==NULL)
   {
     root=temp;
   }
   else
   {
   if(v->data>=data)
   {
     if(v->left!=NULL)
     {
       insert(v->left,data);
     }
     else
     {
        v->left=temp;
        temp->parent=v;
     }
   }  
   else
   {
     if(v->right!=NULL)
     { 
       insert(v->right, data);
     }
     else
     {
       v->right=temp;
       temp->parent=v;
     } 
   }
 }
}

//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
   
//displaying by in-order mechanism
void display(node* v)
  {  
   if(v==NULL)
   {
     return;
   }
   display(v->left);
   cout<<v->data<<"\t";
   display(v->right);
 }
   
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
   
   
//considering each and every case this particular function has been prepared
void deletenode(int key, node* v)
{
  node* temp=root;
  if(v==NULL)
  {
    cout<<"\n \nElement not found !!!\nCan not delete the data entered !";
    return;
  }
  
  //for a leaf node
  if(v->left==NULL && v->right==NULL)
  {
    node* par;
    par=v->parent;
    if(par->data>=v->data)
    {
      par->left=NULL;
    }
    else
      par->right=NULL;
    delete v;
    
  }
   
  //for a node with one child
  else if((v->left==NULL || v->right==NULL ))
   {   
    if(v!=root)
    {
     node* par;
     node* schild;
     par=v->parent; 
     if(v->left==NULL)
      schild=v->right;
     else
      schild=v->left;

     if(par->data>=v->data)
     {
       par->left=schild;
       schild->parent=par;
     }
     else
     {
       par->right=schild;
       schild->parent=par;
     }
    }
    else
    {
        if(v->left==NULL)
          root=v->right;
        else
          root=v->left;
    }
   }
   
  //for a node with two children
  else
  {
    node* maxleft;
    maxleft=v->left;
     
    //maxleft stores the largest number that is smaller than node to be deleted with two children 
    while(maxleft->right!=NULL)
    {
      maxleft=maxleft->right;
    }
    
   //when the maxleft has no left child
   if(maxleft->left==NULL)
   {
     v->data=maxleft->data;
     node* par=maxleft->parent;
     if(par->left==maxleft)
        par->left=NULL;
     else
        par->right=NULL;
   }
     
   //when maxleft has a left child
   else
   {
     v->data=maxleft->data;
     node* par=maxleft->parent;
     if(par->left==maxleft)
        par->left=maxleft->left;
     else
        par->right=maxleft->left;
   }
  }
}

      
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
  
//searching node and returning the node that is found
node* searchnode(node* v, int data)
{
   node* temp=v;
if(v!=NULL)
{
   if(temp->data==data)
   {
     cout<<"\nElement found !!!";
     return temp;
   }
   else if(temp->data>data)
     return searchnode(temp->left,data);
   else
     return searchnode(temp->right, data);
}
else
{ 
  cout<<"\nElement not found !";
  return NULL;
}
}
   
   
      
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
   
//inefficient way of range search
//this function traverses through each and every node, hence inefficient
void rangesrc(node* v,int low, int upp)
{  
   if(v==NULL)
   {
     return;
   }
   rangesrc(v->left,low,upp);
   if(v->data>=low && v->data<=upp)
    {
      cout<<v->data<<"\t";
      rsrc++;
    }
   rangesrc(v->right,low,upp);
 }


void size(node* v)
{  
   if(v==NULL)
   {
     return;
   }
   size(v->left);
   if(v->left==NULL && v->right==NULL) 
     leaf++;
   else
     internal++;
   bstsize++;
   size(v->right);
}
   
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>
   
   
//efficient way of range search
//traverses through only that part of the tree that satisfies the limit conditions
void rsrcn(node* v, int l, int u)
{
   node* temp=v;
   if(v!=NULL)
   {
     if(temp->data>=l && temp->data<=u)
     {
     
     if(temp->data>l)
      rsrcn(temp->left,l,u);
     cout<<temp->data<<"\t";
     if(temp->data<u)
      rsrcn(temp->right,l,u);
     }
     else if(temp->data>l)
       rsrcn(temp->left,l,u);
     else if(temp->data<u)
       rsrcn(temp->right, l,u);
   }
   else
   {
     return;
   }
}


};

   
//1711140
//Suritra Bandyopadhyay
//XD
//Beware of copying >_>

int main()
{
   bsTree BT;
   int n;
   cout<<"\n \nEnter the number of entries you want to enter: ";
   cin>>n;
   
   //INSERTING
   for(int i=0;i<n;i++)
   { cout<<"\nDATA "<<(i+1)<<": ";
     int num=0;
     cin>>num;
     BT.insert(BT.root,num);
   }
   //DISPLAYING
   BT.display(BT.root);
   
   //SEARCHING
   cout<<"\n \nEnter the element to be found: ";
   cin>>n;   
   node* x1=BT.searchnode(BT.root,n);
   cout<<"\n \n";


   //SIZE CALCULATIONS
   BT.size(BT.root);
   cout<<"\nThe total number of internal node: "<<BT.internal<<"\nThe total number of external(leaf) node: "<<BT.leaf<<"\nThe total number of nodes in the binary search tree: "<<BT.bstsize;

   //DELETION
   cout<<"\n \nEnter the node to be deleted: ";
   cin>>n;
   node* x3=BT.searchnode(BT.root,n);
   BT.deletenode(n,x3);
   cout<<"\n";

   //DISPLAYING AFTER DELETION
   BT.display(BT.root);

   //INEFFICIENT RANGE SEARCH
   cout<<"\n \nEnter the lower limit for range search: ";
   int l;
   cin>>l;
   cout<<"\nEnter the upper limit for range search: ";
   int u;
   cin>>u;
   BT.rangesrc(BT.root,l,u);


   //EFFICIENT RANGE SEARCH
   cout<<"\n \nEnter the lower limit for range search: ";
   int l1;
   cin>>l1;
   cout<<"\nEnter the upper limit for range search: ";
   int u1;
   cin>>u1;
   BT.rsrcn(BT.root,l1,u1);
   cout<<"\n";
   return 0;
   
   //SIZE OF RANGE SEARCHING
   cout<<"\n \nThe total number of elements in the range specified is: "<<BT.rsrc;
   cout<<"\n\n";
}
