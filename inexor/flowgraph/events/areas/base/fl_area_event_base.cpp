#include "inexor/flowgraph/events/areas/base/fl_area_event_base.hpp"

namespace inexor {
namespace vscript {

    CAreaEventNode::CAreaEventNode()
    {
        type = INEXOR_VSCRIPT_NODE_TYPE_EVENT;
    }

    CAreaEventNode::~CAreaEventNode()
    {
    }


    bool CAreaEventNode::OnLinkAsChildNodeAttempt(CScriptNode* parent)
    {
        switch(parent->type)
        {
            case INEXOR_VSCRIPT_NODE_TYPE_AREA_BOX:
            case INEXOR_VSCRIPT_NODE_TYPE_AREA_CONE:
            case INEXOR_VSCRIPT_NODE_TYPE_AREA_SPHERE:
            case INEXOR_VSCRIPT_NODE_TYPE_AREA_CYLINDER:
            {
                area = parent;
                area_type = parent->type;
                spdlog::get("global")->debug() << "[3DVS-area-event-node] linked '%s' as event trigger area.", parent->node_name.c_str();
                return true;
                break;
            }
        }
        return false;
    }

    bool CAreaEventNode::OnLinkAsParentNodeAttempt(CScriptNode* child)
    {
        return true;
    }

};
};