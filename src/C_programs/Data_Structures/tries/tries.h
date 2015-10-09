#if !defined(TRIES_DS)


#define TRIES_DS

#define NUM_ALPHABETS 26
/** tries structure for alphabets */
typedef struct _tries {
    int value;
    trie_node_t *link[NUM_ALPHABETS];
} trie_node_t;

#endif
