#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

uint64_t id(uint64_t i, uint64_t j, uint64_t W)
{
    i--;
    j--;
    return i * W + j;
}

class Node
{
private:
    Node *parent = nullptr;
    uint64_t rank = 0;

public:
    Node *getParent(vector<Node *> *nodeList)
    {

        if (parent == nullptr)
        {
            for (auto &&n : *nodeList)
            {
                n->parent = this;
            }
            return this;
        }

        nodeList->push_back(this);
        return parent->getParent(nodeList);
    }

    static Node *Union(Node *a, Node *b)
    {
        vector<Node *> nodeList;
        auto aRoot = a->getParent(&nodeList);
        nodeList.clear();
        auto bRoot = b->getParent(&nodeList);

        if (aRoot->rank > bRoot->rank)
        {
            bRoot->parent = aRoot;
            return aRoot;
        }
        else if (aRoot->rank < bRoot->rank)
        {
            aRoot->parent = bRoot;
            return bRoot;
        }
        else if (aRoot != bRoot)
        {
            aRoot->parent = bRoot;
            bRoot->rank++;
            return bRoot;
        }

        return aRoot;
    }
};

int main()
{
    uint64_t H, W;
    cin >> H >> W;

    vector<vector<Node *>> grid(H, vector<Node *>(W, nullptr));

    uint64_t Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        uint64_t t;
        cin >> t;
        if (t == 1)
        {
            uint64_t r, c;
            cin >> r >> c;
            r--;
            c--;

            Node *node = new Node();
            if (r != 0 && grid[r - 1][c] != nullptr)
            {
                node = Node::Union(grid[r - 1][c], node);
            }
            if (c != 0 && grid[r][c - 1] != nullptr)
            {
                node = Node::Union(grid[r][c - 1], node);
            }
            if (r < H - 1 && grid[r + 1][c] != nullptr)
            {
                node = Node::Union(grid[r + 1][c], node);
            }
            if (c < W - 1 && grid[r][c + 1] != nullptr)
            {
                node = Node::Union(grid[r][c + 1], node);
            }
            grid[r][c] = node;
        }
        else
        {
            uint64_t ar, ac, br, bc;
            cin >> ar >> ac >> br >> bc;
            ar--, ac--, br--, bc--;

            if (grid[br][bc] == nullptr || grid[ar][ac] == nullptr)
            {
                cout << "No" << endl;
                continue;
            }

            vector<Node *> nodeList;
            auto aRoot = grid[ar][ac]->getParent(&nodeList);
            nodeList.clear();
            auto bRoot = grid[br][bc]->getParent(&nodeList);
            if (aRoot == bRoot)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}