#include <bits/stdc++.h>

#define mx 10
#define mod 7
#define ll long long

using namespace std;

struct node
{
      int data;
      bool deleted;
      node(int data)
      {
            this->data = data;
            deleted = false;
      }
};

node *hashTable[mx];

int hashFun(int index)
{
      return (index % mod);
}

void Insert(int data)
{
      int index = hashFun(data);
      node *newNode = new node(data);
      cout << "insert : " << index << endl;
      int full = 0;
      while (hashTable[index] != NULL && !hashTable[index]->deleted)
      {
            if (full > mod * 2)
                  return;
            full++;
            index = (index + full * full) % mod;
      }
      hashTable[index] = newNode;
}

void Search(int data)
{
      int index = hashFun(data);
      bool got = false;
      int full = 0;
      while (hashTable[index] != NULL)
      {
            if (hashTable[index]->data == data && !hashTable[index]->deleted)
            {
                  got = true;
                  break;
            }
            if (full > mod * 2)
                  break;
            full++;
            index = (index + full * full) % mod;
      }

      if (got)
      {
            cout << hashTable[index]->data << "\n";
      }
      else
      {
            cout << "not found !! (- _-) !!\n";
      }
}

void showHash()
{
      for (int i = 0; i < 7; i++)
      {
            if (hashTable[i] != NULL && !hashTable[i]->deleted)
            {
                  cout << hashTable[i]->data << "\n";
            }
            else
            {
                  cout << "not found !! (-_-) !!\n";
            }
      }
}

void Delete(int data)
{
      int index = hashFun(data);
      int full = 0;
      while (hashTable[index] != NULL)
      {
            if (hashTable[index]->data == data && !hashTable[index]->deleted)
            {
                  cout << "(*_-_*) !!Deleted\n";
                  hashTable[index]->deleted = true;
                  return;
            }
            if (full > mod * 2)
                  break;
            full++;

            index = (index + full * full) % mod;
      }
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);

      int data[] = {50, 700, 76, 85, 92, 73, 101};
      int n = sizeof(data) / sizeof(data[0]);

      for (int i = 0; i < n; i++)
            hashTable[i] = NULL;
      for (int i = 0; i < 7; i++)
      {
            Insert(data[i]);
      }
      showHash();
      cout << "++++++search++++++++++++++++++++++++++++++++\n";
      Search(85);
      cout << "++++++++Delete++++++++++++++++++++++++++++++\n";
      Delete(85);
      cout << "++++++++++++++Delete++++++++++++++++++++++++\n";
      Delete(85);
      cout << "++++++++++++search++++++++++++++++++++++++++\n";
      Search(85);
      cout << "+++++++showHash+++++++++++++++++++++++++++++++\n";
      showHash();
      cout << "+++++++++Insert+++++++++++++++++++++++++++++\n";
      Insert(90);
      cout << "+++++++showHash+++++++++++++++++++++++++++++++\n";
      showHash();

      return 0;
}