
#if !defined(GRAPH_UTILS)
#define GRAPH_UTILS



/** Single node of a graph */
typedef struct adl_graph_node {
    int vertex;
    /** Each edge points to another node */
    struct adl_graph_node  *edge;
}adl_graph_node;


/** create a node for a vertex to hold */
void _adl_create_node();

/** Insert edge in one of the vertices */
void _adl_insert_edge(adl_graph_node *ghead, int vertex);


/** creates a graph with supplied number of vertices */
adl_graph_node* _create_graph(int max_ver);

/** print graph contents */
void _print_graph(adl_graph_node *ghead, int vertices);


/** free memory allocated to adl graph */
void _free_graph(adl_graph_node *ghead);


#endif


