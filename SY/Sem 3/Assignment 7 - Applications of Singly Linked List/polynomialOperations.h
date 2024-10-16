typedef struct node {
    int coef, exp;
    struct node *next;
} POLY;

void create(POLY *head) {
    POLY *temp = head, *newnode;
    int i, n;
    printf("\nHow many terms ? ");
    scanf("%d", &n);
    printf("\nEnter the terms in descending order of power:\n");
    
    for (i = 1; i <= n; i++) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        printf("\nEnter Coeff and Exponent: ");
        scanf("%d%d", &newnode->coef, &newnode->exp);
        temp->next = newnode;
        temp = newnode;
    }
}

void display(POLY *head) {
    POLY *temp;
    for (temp = head->next; temp != NULL; temp = temp->next)
        printf("%dx^%d ", temp->coef, temp->exp);
    printf("\n");
}

void add(POLY *p1, POLY *p2, POLY *p3) {
    POLY *t1 = p1->next, *t2 = p2->next, *t3 = p3, *newnode;
    
    while (t1 != NULL && t2 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        if (t1->exp == t2->exp) {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef + t2->coef;
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef;
            t1 = t1->next;
        } else {
            newnode->exp = t2->exp;
            newnode->coef = t2->coef;
            t2 = t2->next;
        }
        t3->next = newnode;
        t3 = newnode;
    }
    
    while (t1 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        newnode->exp = t1->exp;
        newnode->coef = t1->coef;
        t3->next = newnode;
        t3 = newnode;
        t1 = t1->next;
    }
    
    while (t2 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        newnode->exp = t2->exp;
        newnode->coef = t2->coef;
        t3->next = newnode;
        t3 = newnode;
        t2 = t2->next;
    }
}

void subtract(POLY *p1, POLY *p2, POLY *p3) {
    POLY *t1 = p1->next, *t2 = p2->next, *t3 = p3, *newnode;
    
    while (t1 != NULL && t2 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        if (t1->exp == t2->exp) {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef - t2->coef;
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef;
            t1 = t1->next;
        } else {
            newnode->exp = t2->exp;
            newnode->coef = -t2->coef;
            t2 = t2->next;
        }
        t3->next = newnode;
        t3 = newnode;
    }

    while (t1 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        newnode->exp = t1->exp;
        newnode->coef = t1->coef;
        t3->next = newnode;
        t3 = newnode;
        t1 = t1->next;
    }

    while (t2 != NULL) {
        newnode = (POLY *)malloc(sizeof(POLY));
        newnode->next = NULL;
        newnode->exp = t2->exp;
        newnode->coef = -t2->coef;
        t3->next = newnode;
        t3 = newnode;
        t2 = t2->next;
    }
}

void multiply(POLY *p1, POLY *p2, POLY *p3) {
    POLY *t1, *t2, *newnode, *t3 = p3, *temp;
    POLY *tempPoly = (POLY *)malloc(sizeof(POLY)); // Temporary result list

    for (t1 = p1->next; t1 != NULL; t1 = t1->next) {
        tempPoly->next = NULL; // Start from scratch for each t1 term
        temp = tempPoly;
        for (t2 = p2->next; t2 != NULL; t2 = t2->next) {
            newnode = (POLY *)malloc(sizeof(POLY));
            newnode->next = NULL;
            newnode->coef = t1->coef * t2->coef;
            newnode->exp = t1->exp + t2->exp;
            temp->next = newnode;
            temp = newnode;
        }
        add(p3, tempPoly, p3); // Add the current result to final polynomial
    }
}

void differentiate(POLY *p, POLY *dp) {
    POLY *t1 = p->next, *newnode, *t2 = dp;
    
    while (t1 != NULL) {
        if (t1->exp != 0) {
            newnode = (POLY *)malloc(sizeof(POLY));
            newnode->coef = t1->coef * t1->exp;
            newnode->exp = t1->exp - 1;
            newnode->next = NULL;
            t2->next = newnode;
            t2 = newnode;
        }
        t1 = t1->next;
    }
}

int evaluate(POLY *p, int x) {
    POLY *temp = p->next;
    int result = 0;
    
    while (temp != NULL) {
        result += temp->coef * pow(x, temp->exp);
        temp = temp->next;
    }
    
    return result;
}
