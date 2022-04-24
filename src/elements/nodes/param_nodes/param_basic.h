/***************************
@Author: wmz
@Contact: wmengzhao@qq.com
@File: param_basic.h
@Time: 2022/4/14 7:02 PM
@Desc: TODO
***************************/

#ifndef GRAPHANNS_PARAM_BASIC_H
#define GRAPHANNS_PARAM_BASIC_H

#include "../../CGraph/src/CGraph.h"
#include "../../../utils/utils_include.h"

class ParamBasic : public CGraph::GParam {
public:
    /**
     * parameters for build
     */
    std::string base_path; // base vector
    VecValType *data = nullptr;
    unsigned num = 0;
    unsigned dim = 0;
    unsigned cur_id = 0;    //

    std::string index_path; // path to graph index

    typedef std::vector<std::vector<SimpleNeighbor> > graph_neighbor;
    typedef std::vector<std::vector<unsigned> > graph_matrix;

    graph_neighbor graph_n;
    graph_matrix graph_m;

    /**
     * parameters for search
     */
    std::string query_path;    // query vector
    VecValType *query = nullptr;
    unsigned q_num = 0;
    unsigned q_dim = 0;
    std::string groundtruth_path;  // groundtruth id
    unsigned *gt = nullptr;
    unsigned gt_num = 0;
    unsigned gt_dim = 0;

    unsigned top_k = 20;
    unsigned search_L = top_k + 500;
    unsigned query_id = 0;

    std::vector<SearchPool> sp;
    std::vector<std::vector<unsigned> > results;

    CVoid reset() override {
        sp.clear();
    }

};

#endif //GRAPHANNS_PARAM_BASIC_H
