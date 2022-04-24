/***************************
@Author: wmz
@Contact: wmengzhao@qq.com
@File: search_region.h
@Time: 2022/4/8 10:24 AM
@Desc: perform multiple queries in SearchRegion, determined by "q_num" parameter
***************************/

#ifndef GRAPHANNS_SEARCH_REGION_H
#define GRAPHANNS_SEARCH_REGION_H

#include "src/CGraph.h"
#include "../nodes/param_nodes/param_include.h"

class SearchRegion : public CGraph::GRegion {
public:
    CBool isHold() override {
        auto g_param = CGRAPH_GET_GPARAM(ParamNPG, GRAPH_INFO_PARAM_KEY);
        g_param->query_id++;
        return g_param->query_id < g_param->q_num;
    }
};

#endif //GRAPHANNS_SEARCH_REGION_H
