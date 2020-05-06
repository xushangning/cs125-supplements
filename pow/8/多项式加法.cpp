Node* add_poly(Node* a, Node* b) {
    Node *head = new Node, *cur = head;
    int x;
    while (a!=NULL && b!=NULL) {
        Node *p = new Node;
        //if same order
        if (a->order == b->order) {
            x = a->coeff + b->coeff;
            if (x!=0) {
                p->order = a->order;
                p->coeff = x;
                a = a->nxt;
                b = b->nxt;
                cur->nxt = p;
                cur = cur->nxt;
            }
            else {a = a->nxt; b = b->nxt; delete p;}
        }
        //find the higher order
        else if (a->order > b->order) {
            //the coffecient of the input Node can be 0
            if (a->coeff != 0) {
                p->order = a->order;
                p->coeff = a->coeff;
                a = a->nxt;
                cur->nxt = p;
                cur = cur->nxt;
            }
            else a = a->nxt;
        }
        else {
            if (b->coeff != 0) {
                p->order = b->order;
                p->coeff = b->coeff;
                b = b->nxt;
                cur->nxt = p;
                cur = cur->nxt;
            }
            else b = b->nxt;
        }
    }
    //connect the rest part
    if (a == NULL) cur->nxt = b;
    else cur->nxt = a;
    
    if (head->nxt == NULL) {head->coeff=0; head->order=0; head->nxt=NULL; return head;}
    else {Node *p = head->nxt; delete head; return p;}
}
