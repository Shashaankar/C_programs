#include<stdio.h>
#include <stdlib.h>
#include "graph_utils.h"




/**@brief: Create graph structure and return the head pointer */

adl_graph_node* _create_graph(int max_ver) {

    adl_graph_node *ghead = (adl_graph_node *) malloc(sizeof(adl_graph_node) * max_ver);
    int i = 0;
    if (!ghead) {
        printf("\n create_graph: malloc failed !!");
        exit(-1);
    }

    /** Initialize vertex to -1 */
    for (i=0; i < max_ver; i++) {
        ghead[i].vertex = -1;
    }

    return ghead;
}


/** @brief: Create graph root to hold graph meta data 
 * and also creates a graph structure to hold graph nodes */

adl_graph_root* _create_graph_root(int max_ver, int graph_type) {

    adl_graph_root *groot = (adl_graph_root *) malloc(sizeof(adl_graph_root));
    if (groot) {
        groot->ghead = _create_graph(max_ver);
        groot->graph_type = graph_type;
    } else {
        printf("\n create_graph_root failed");
        exit(-1);
    }

    return groot;
}


/**@brief: print contenets of graph  */

void _print_graph(adl_graph_root *groot, int vertices) {

    adl_graph_node *temp = NULL;
    int vertex = 0;
    if (!groot || !groot->ghead) {
        printf("\n graph is NULL ");
        return;
    }

    temp = groot->ghead;
    for (int i =0; i < vertices; i++) {

        /** goto next vertex in series */
        temp = (adl_graph_node *)((char *)temp + sizeof(adl_graph_node));
        /** loop through edges of each vertex */
        if (temp && temp->vertex != -1) {

            printf("\n ######## Vertex: %d", temp->vertex);
            vertex = temp->vertex;
            temp = temp->edge;

            /** loop until all the edges from a vertex are done 
             * last node edge will have NULL */
            while (temp) {

                printf("\n Edge from Vertex %d to %d", vertex, temp->vertex);
                temp = temp->edge;
            }
        }
    }


}



/** @brief: insert a new edge into given graph 
 * edge_from: starting point of a edge 
 * edge_to: ending point of edge */

void _insert_graph_node(adl_graph_node *ghead, int enge_from, int edge_to) {
}


/**@brief: free memeory allocated to graph structure  */

void _free_graph(adl_graph_root *groot) {

    free(groot->ghead);
    free(groot);
}
