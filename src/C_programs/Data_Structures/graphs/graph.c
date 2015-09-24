#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "graph_utils.h"




void main() {

    int max_ver = 10;
    adl_graph_node *ghead = NULL;
    ghead = _create_graph(max_ver);


    _free_graph(ghead);

} 
