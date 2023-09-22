#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegTree
{
public:
    vector<ll> tree;
    int n;
    vector<int>arr;

    // Constructor to build the segment tree
    SegTree(int _n, vector<int> a)
    {
        tree.resize(5 * _n, 0); // Initialize the tree with zeros
        arr=a;
        n = _n;
        build(0, n - 1, 0, arr); // Build the segment tree
    }

    // Query function to get the sum in a range [x, y]
    ll query(int x, int y)
    {
        return query(0, n - 1, 0, x, y);
    }

    // Update function to modify the value at index ind
    void update(int ind, int val)
    {
        update(0, n - 1, 0, ind, val);
    }

private:
    // Build the segment tree
    void build(int l, int r, int i, vector<int> &arr)
    {
        if (l == r)
        {
            // Leaf node, store the value from the original array
            tree[i] = arr[l];
        }
        else
        {
            int mid = (l + r) / 2;

            // Recurse on the left child
            build(l, mid, 2 * i + 1, arr);
            // Recurse on the right child
            build(mid + 1, r, 2 * i + 2, arr);
            
            // Internal node i will have the sum of both of its children
            tree[i] = min(tree[2 * i + 1] , tree[2 * i + 2]);
        }
    }

    // Update function to modify the value at index idx
    void update(int l, int r, int i, int idx, int val)
    {
        if (l == r)
        {
            // Leaf node, update the value
            tree[i] = val;
        }
        else
        {
            int mid = (l + r) / 2;
            if (l <= idx && idx <= mid)
            {
                // If idx is in the left child, recurse on the left child
                update(l, mid, 2 * i + 1, idx, val);
            }
            else
            {
                // If idx is in the right child, recurse on the right child
                update(mid + 1, r, 2 * i + 2, idx, val);
            }
            
            // Internal node i will have the sum of both of its children
            tree[i] = min(tree[2 * i + 1] , tree[2 * i + 2]);
        }
    }

    // Query function to get the sum in a range [x, y]
    ll query(int l, int r, int i, int x, int y)
    {
        if (r < x || l > y)
        {
            // Range represented by node i is completely outside the given range [x, y]
            return 1e9;
        }
        if (l >= x && r <= y)
        {
            // Range represented by node i is completely inside the given range [x, y]
            return tree[i];
        }

        // Range represented by node i is partially inside and partially outside the given range [x, y]
        int mid = (l + r) / 2;
        int p1 = query(l, mid, 2 * i + 1, x, y);     // Query left child
        int p2 = query(mid + 1, r, 2 * i + 2, x, y); // Query right child
        return min(p1 , p2);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    SegTree st(n, v); // Create a segment tree with the given array

    // for (auto ele : st.tree)
    //     cout << ele << " "; // Print the segment tree for demonstration
    for (int i = 0; i < q; i++) {
        int x, y;
        char type;
        cin >> type >> x >> y;
        if (type == 'u') {
            // Update operation
            st.update(x - 1, y); // Subtract 1 to convert to 0-based index
        } else if (type == 'q') {
            // Query operation
            cout << st.query(x - 1, y - 1) << endl; // Subtract 1 to convert to 0-based index
        }
    }
    

    return 0;
}
