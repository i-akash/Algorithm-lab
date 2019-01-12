#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

#define innerNode '*'

struct node
{
      char nodechar;
      int value;

      node *leftchild, *rightchild;

      node(char nodechar, int value)
      {
            this->nodechar = nodechar;
            this->value = value;
            leftchild = rightchild = NULL;
      }
};

struct compare
{
      bool operator()(node *a, node *b)
      {
            return (a->value > b->value);
      }
};

string code[mx];

int converter(char a)
{
      return (a - 'A');
}

void codeGenerator(node *root, string bseq)
{
      if (root == NULL || !root)
            return;

      if (root->nodechar != innerNode)
            code[converter(root->nodechar)] = bseq;

      codeGenerator(root->leftchild, bseq + '0');
      codeGenerator(root->rightchild, bseq + '1');
}

void Huffman(char seq[], int freq[], int n)
{
      priority_queue<node *, vector<node *>, compare> pq;

      for (int i = 0; i < n; i++)
      {
            pq.push(new node(seq[i], freq[i]));
      }

      while (pq.size() != 1)
      {
            node *leftc = pq.top();
            pq.pop();
            node *rightc = pq.top();
            pq.pop();

            node *top = new node(innerNode, leftc->value + rightc->value);

            top->leftchild = leftc;
            top->rightchild = rightc;

            pq.push(top);
      }
      codeGenerator(pq.top(), "");
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      char seq[] = {'a', 'b', 'c', 'd', 'e', 'f'};
      int freq[] = {5, 9, 12, 13, 16, 45};
      int n = sizeof(seq) / sizeof(seq[0]);
      Huffman(seq, freq, n);

      for (int i = 0; i < n; i++)
      {
            cout << seq[i] << ": " << code[converter(seq[i])] << "\n";
      }
      return 0;
}