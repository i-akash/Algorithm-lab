#include <bits/stdc++.h>

#define mx 1000
#define mod 100
#define ll long long

using namespace std;

struct profile
{
      string name, occupetion;
      ll mobile;
};

struct node
{
      profile person;
      node *nextNode, *prevNode;
      node()
      {
            nextNode = prevNode = NULL;
      }
      node(string name, string occupetion, ll mobile)
      {
            person.name = name;
            person.occupetion = occupetion;
            person.mobile = mobile;

            nextNode = prevNode = NULL;
      }
};

int hashFun(ll no)
{
      return (no % mod);
}

node *hashTable[mod + 5];

void Insert(string name, string occupetion, ll mobile)
{
      int index = hashFun(mobile);

      node *last = hashTable[index];
      node *newNode = new node(name, occupetion, mobile);
      if (hashTable[index] == NULL)
      {
            hashTable[index] = newNode;
            return;
      }

      while (last->nextNode != NULL)
            last = last->nextNode;

      newNode->prevNode = last;
      last->nextNode = newNode;
}

void Search(ll no)
{
      int index = hashFun(no);
      node *last = hashTable[index];

      while (last != NULL)
      {
            if (last->person.mobile == no)
            {
                  cout << last->person.name << " " << last->person.occupetion << "\n";
                  return;
            }
            cout << last->person.name << " " << last->person.occupetion << "\n";

            last = last->nextNode;
      }
}

void Delete(ll no)
{
      int index = hashFun(no);
      node *last = hashTable[index];

      while (last != NULL)
      {
            if (no == last->person.mobile)
            {
                  if (last->prevNode == NULL)
                  {
                        hashTable[index] = last->nextNode;
                        hashTable[index]->prevNode = NULL;
                  }
                  else
                  {
                        last->prevNode->nextNode = last->nextNode;
                  }
                  return;
            }
            last = last->nextNode;
      }
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);

      for (int i = 0; i < mod; i++)
            hashTable[i] = NULL;

      Insert("akash", "sylhet", 7);
      Insert("bkash", "cylhet", 107);
      Insert("ckash", "dylhet", 207);
      Search(7);
      cout << "------------------------------------------------\n";
      Delete(7);
      cout << "------------------------------------------------\n";
      Search(7);
      return 0;
}