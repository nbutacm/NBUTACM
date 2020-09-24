#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
vector<string> v;

class BST {
public:
    struct node {
        struct ele {
            string val;
            int cnt;
            ele(const string &val) : val(val), cnt(1) { }
        } ele; 
        node* lc;
        node* rc;
        node(const string& val) : ele(val), lc(nullptr), rc(nullptr) { }
    };
    node * root = nullptr;
    // 插入节点
    node* Insert(const string& val) {
        if (!root) {
            this->root = new node(val);
            v.emplace_back(val);
            return root;
        }
        node* now = root;
        bool status = false;
        while (1) {
            if (root->ele.val == val) {
                root->ele.cnt++;
                break;
            } else if (root->ele.val > val) {
                if (root->lc == nullptr) {
                    status = true;
                    root->lc = new node(val);
                    break;
                }
                root = root->lc;
            } else {
                if (root->rc == nullptr) {
                    status = true;
                    root->rc = new node(val);
                    break;
                }
                root = root->rc;
            }
        }
        if (status) v.emplace_back(val);
        return this->root = now;
    }

    BST::node* findkey(const string& key) {
        if (root == nullptr) return nullptr;
        node *temp = root;
        while (temp) {
            if (temp->ele.val == key) {
                return temp;
            }
            if (temp->ele.val < key) {
                temp = temp->rc;
            } else {
                temp = temp->lc;
            }
        }

        return nullptr;
    }
};

int main(void) {

    freopen("../user.txt", "r", stdin);
    char name[50];
	int id;
    BST user;
    clock_t startTime = clock();
    while (~scanf("%d %s", &id, name)) {
        user.Insert(string(name));
    }

    cout << "读取完成...创建BST成功" << endl;
    ofstream fout("password_BST.txt", ios::out);
    // user.post_oder(user.root, fout);
    for (auto & x : v) {
        auto it = user.findkey(x);
        fout << it->ele.val << "\t" << it->ele.cnt << endl;
    }
    clock_t endTime = clock();
    fout.close();
    
    double result = (double)(endTime - startTime);
    ofstream f("result_time/password_BST_result.txt", ios::out);

    f << "The run time for BST is: " << fixed << setprecision(3) << result / CLOCKS_PER_SEC << "s" << endl;
    f.close();

    return 0;
}
