//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <stdio.h>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
int max=3;
float proc=0.5;

class Node
{
public:
 int key;
// ������ ��� �������� ���������� �� ���� ������� ������

    Node **forward;
 Node(int, int);
};

  Node::Node(int key, int level)
{
 this->key = key;

  // ������������ ������ ��� ���������
    forward = new Node*[level+1];
    // ��������� ������ ������ 0 (NULL)
    memset(forward, 0, sizeof(Node*)*(level+1));
};
// ����� ��� ������ ��������
class SkipList
{
    // ������������ ������� ��� ����� ������ ��������
    int MAXLVL;
    // P - ���� ����� � �������
    // ��������� i ����� ����� ��������� ������ i + 1
   float P;
    // ������� ������� ������ ��������
    int level;
    // ��������� �� ���� ���������
    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
   Node* createNode(int, int);
    void insertElement(int);
    void displayList();
};

SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
   level = 0;
    // ������� ���� ��������� � �������������� ���� -1
    header = new Node(-1, MAXLVL);
};
// ������� ��������� ������� ��� ����
int SkipList::randomLevel()
{
   float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
   {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};
// ������� ����� ����

Node* SkipList::createNode(int key, int level)
{
   Node *n = new Node(key, level);
   return n;
};
// �������� ������ ���� � ������ ��������
void SkipList::insertElement(int key)
{
    Node *current = header;
   // ������� ������ ���������� � �������������� ���
    Node *update[MAXLVL+1];
   memset(update, 0, sizeof(Node*)*(MAXLVL+1));
      // ������ � ������ �������� ������ ������ ��������
   //   ����������� ������� ��������� ������, ���� �������
  //    ������, ��� ���� ���� ����� � �������
   //   � ��������� ������ ����������� ������� � ���������� �
      //  ������������� �� ���� ������� ���� � ���������� �����

        for (int i = level; i >= 0; i--)
{
        while (current->forward[i] != NULL &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    /* ������ ������ 0 � ������ ��������� ��
       �����, ������� �������� �������� �������� ���
       �������� ����.
    */
    current = current->forward[0];
    /* ���� ��� ����� NULL, ��� ��������, ��� �� ��������
       �� ����� ������ ��� ������� ���� �� �����
       ����� �������� ����, ��� ��������, ��� �� ������ ��������
       ���� ����� ����������� [0] � ������� ����� */
    if (current == NULL || current->key != key)
    {
        // ���������� ��������� ������� ��� ����
        int rlevel = randomLevel();
        // ���� ��������� ������� ������ �������� ������
        // ������� (���� � ��������� ������� �������� �
        // ���� ������), �������������� �������� ���������� ����������
        // � ��������� ��� ����������� �������������
        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;
            // ��������� ������� ������� ������
            level = rlevel;
        }
        // ������� ����� ���� �� ��������� �������
        Node* n = createNode(key, rlevel);
        // ��������� ����, ����������� ���������
        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
       }
        cout << "Successfully Inserted key " << key << "\n";
    }
};

// ����������� ������ �������� �� ������ ��������
void SkipList::displayList()
{
    cout<<"\n*****Skip List*****"<<"\n";
   for (int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
       {
            cout << node->key<<" ";
            node = node->forward[i];
       }
        cout << "\n";
    }
};
//---------------------------------------------------------------------------
struct Stack {
int info;
TEdit *edit;
Stack *next;
};
struct Stack * cur = NULL;
struct Stack * top = NULL;

int left_pos = 30;

//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{

// max=Edit2->Text.ToInt();
}
//---------------------------------------------------------------------------


 void __fastcall TForm1::Button1Click(TObject *Sender)
{
//SkipList lst(max, proc);
//lst.insertElement(Form1->Edit1->Text.ToInt());
top = new Stack();
top->edit = new TEdit(Form1);
top->edit->Parent=Form1;
top->edit->Text=Edit1->Text;
top->edit->Width=50;
top->edit->Height=15;
top->edit->Font->Size=10;
top->edit->Top = 100;
top->edit->Left = left_pos;
top->next = cur;

cur = top;
left_pos += 70;
}
