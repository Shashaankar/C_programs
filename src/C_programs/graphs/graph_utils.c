#include<stdio.h>
#include <stdlib.h>
#include "graph_utils.h"


/**@brief: Create graph structure and return the head pointer */

adl_graph_node* _create_graph(int max_ver) {

    adl_graph_node *ghead = (adl_graph_node *) malloc(sizeof(adl_graph_node) * max_ver);
    if (!ghead) {
        printf("\n create_graph: malloc failed !!");
        exit(-1);
    }

    return ghead;
}


/**@brief: print contenets of graph  */

void _print_graph(adl_graph_node *ghead, int vertices) {


}



/**@brief: free memeory allocated to graph structure  */

void _free_graph(adl_graph_node *ghead) {

    free(ghead);
}
