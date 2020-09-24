#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

class BST {
public:
    struct node {
        ll val;
        node* lc;
        node* rc;
        node(ll val) : val(val), lc(nullptr), rc(nullptr) { }
    };
    node * root = nullptr;
    // 插入节点
    node* Insert(ll val) {
        if (!root) {
            this->root = new node(val);
            return root;
        }
        node* now = root;
        while (1) {
            if (root->val > val) {
                if (root->lc == nullptr) {
                    root->lc = new node(val);
                    break;
                }
                root = root->lc;
            } else {
                if (root->rc == nullptr) {
                    root->rc = new node(val);
                    break;
                }
                root = root->rc;
            }
        }
        // this->root = now;
        return this->root = now;
    }

    bool findkey(ll key) {
        // cout << root << endl;
        if (root == nullptr) return false;
        node *temp = root;
        while (temp) {
            if (temp->val == key) {
                return true;
            }
            if (temp->val < key) {
                temp = temp->rc;
            } else {
                temp = temp->lc;
            }
        }

        return false;
    }
};

int main(void) {
    FAST_IO;

    freopen("../user.txt", "r", stdin);
    string name;
	int id;
    BST user;
    while (cin >> id >> name) {
        user.Insert(id);
    }
    cout << "读入成功 BST创建成功...." << endl;
    ifstream fin("../random_id.txt", ios::in);
    clock_t startTime = clock();
    int cnt = 0;
    while (fin >> id) {
        if (user.findkey(id)) {
            cnt++;
        }
    }
    fin.close();
    clock_t endTime = clock();
	ofstream fout("BST_find.txt", ios::out);
    cout << "The total of find for BST : " << cnt << " users" << endl;
    fout << "The run time for BST is: " << fixed << setprecision(3) << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}