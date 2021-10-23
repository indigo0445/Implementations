struct avl_node{
    avl_node* p=nullptr;
    avl_node* l=nullptr;
    avl_node* r=nullptr;
    int nb;
    int d;
    avl_node(avl_node* parent, avl_node* left, avl_node* right, int nodesBelow, int data){
        p = parent;
        l = left;
        r = right;
        nb = nodesBelow;
        d = data;
    }
};
//YES DUPLICATES
//things equal to go right
class avl_tree{
public:
    avl_node* root=nullptr;
    int sz = 0;
public:
    avl_tree(){}
    // ~avl_tree(){}
    avl_node* find(int val){
        avl_node* n = root;
        while(true){
            if(val == n->d) return n;
            if(val < n->d && n->l != nullptr){
                n = n->l;
            } else if(val > n->d && n->r != nullptr){
                n = n->r;
            } else{
                break;
            }
        }
        return nullptr;
    }
    int countBelow(avl_node* n){
        return (n->l==nullptr ? 0 : n->l->nb+1) + (n->r==nullptr ? 0 : n->r->nb+1);
    }
    // void rotateL(avl_node* pivot){
    //     if(pivot->p == nullptr){
    //         root = pivot->r;
    //         pivot->r->p = nullptr;
    //     } else{
    //         (pivot->d < pivot->p->d ? pivot->p->l : pivot->p->r) = pivot->r;
    //         pivot->r->p = pivot->p;
    //     }
    //     pivot->r->l = pivot;
    //     pivot->p = pivot->r;
    //     if(pivot->r->l != nullptr){
    //         //attach pivot->r->l to pivot->r
    //         pivot->r = pivot->r->l;
    //         pivot->r->l->p = pivot;
    //     } else{
    //         pivot->r = nullptr;
    //     }
    //     pivot->nb = countBelow(pivot);
    //     pivot->p->nb = countBelow(pivot->p);
    //     //IF PIVOT->R HAS A LEFT CHILD THEN NEEDA PUT THAT LEFT CHILD AS PIVOT->R
    // }
    void rotateL(avl_node* pivot){
        //pivot is the top of the unbalanced subtrees
        
    }
    void rotateR(avl_node* pivot){
        //leftchild is now parent of pivot
        //parent of pivot is now parent of leftchild
        //this first, because we dont change pivot
        if(pivot->p == nullptr){
            root = pivot->l;
            pivot->l->p = nullptr;
        } else{
            (pivot->d < pivot->p->d ? pivot->p->l : pivot->p->r) = pivot->l;
            pivot->l->p = pivot->p;
        }
        pivot->l->r = pivot;
        pivot->p = pivot->l;
        if(pivot->l->r != nullptr){
            //attach pivot->r->l to pivot->r
            pivot->l = pivot->l->r;
            pivot->l->r->p = pivot;
        } else{
            pivot->l = nullptr;
        }

        pivot->nb = countBelow(pivot);
        pivot->p->nb = countBelow(pivot->p);
    }
    void rebalance(avl_node* n){
        //starts at n and goes to parent (inclusive)
        while(n != nullptr){
            int szL = (n->l==nullptr ? 0 : n->l->nb+1);
            int szR = (n->r==nullptr ? 0 : n->r->nb+1);
            printf("szL: %d, szR: %d\n", szL, szR);
            if(szL-szR > 1){
                //szL bigger
                rotateR(n);
                break;
            } else if(szR-szL > 1){
                rotateL(n);
                break;
            }
            //if diff > 1 then rotate accordingly
            n = n->p;
        }
    }
    void insert(int val){
        //IF 0 OR 1 CHILDREN THEN THIS WORKS FINE, BUT FAILS WHEN HAS 2
        if(sz == 0){
            root = new avl_node(nullptr, nullptr, nullptr, 0, val);
        } else{
            // root->nb++;
            avl_node* n = root;
            while(true){
                n->nb++;
                if(val < n->d && n->l != nullptr){
                    n = n->l;
                } else if(val >= n->d && n->r != nullptr){
                    n = n->r;
                } else{
                    break;
                }
            }
            //n is a leaf
            (val < n->d ? n->l : n->r) = new avl_node(n, nullptr, nullptr, 0, val);
            rebalance(n);
        }
        sz++;
    }
    avl_node* leftmost(avl_node* n){
        while(n->l != nullptr){
            n = n->l;
        }
        return n;
    }
    avl_node* rightmost(avl_node* n){
        while(n->r != nullptr){
            n = n->r;
        }
        return n;
    }
    void eraseLeaf(avl_node* n){
        //n is not the root, so it has parent
        (n->d < n->p->d ? n->p->l : n->p->r) = nullptr;
        n->p->nb = countBelow(n->p);
        rebalance(n->p);
        delete n;
    }
    void erase(avl_node* n){
        //for left branch: find rightmost node
        //for right branch: find leftmost node

        //if left is not empty then find rightmost from it
        //else if right is not empty then find leftmost from it
        //else set root=nullptr and erase n
        if(n->l != nullptr){
            //m is a leaf
            avl_node* m = rightmost(n->l);
            n->d = m->d;
            eraseLeaf(m);
        } else if(n->r != nullptr){
            avl_node* m = leftmost(n->r);
            n->d = m->d;
            eraseLeaf(m);
        } else if(n != root){
            eraseLeaf(n);
        } else{
            delete n;
            root = nullptr;
        }
    }
    void erase(int val) { erase(find(val)); }
    int size(){ return sz; }
    //awlays insert and THEN rotate
};
