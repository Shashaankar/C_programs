#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "graph_utils.h"




void main() {

    int max_ver = 10;
    adl_graph_root *groot = NULL;
    groot = _create_graph_root(max_ver, DIRECTED_GRAPH);

    _print_graph(groot, max_ver);


    _free_graph(groot);

} 
