/// @file fl_rendering.h
/// @author Johannes Schneider
/// @brief Renderer for nodes and node relations

#ifndef INEXOR_VSCRIPT_RENDERING_HEADER
#define INEXOR_VSCRIPT_RENDERING_HEADER

#include <vector>

#include "inexor/engine/engine.h"

#include "inexor/geom/curves/curvebase.h"
#include "inexor/geom/geom.h"

#include "inexor/flowgraph/debugger/fl_dbgrays.h"
#include "inexor/flowgraph/node/fl_nodebase.h"


namespace inexor {
namespace vscript {

    extern const float boxsize;

    enum VSCRIPT_ENTITY_BOX_ORIENTATION
    {
        VSCRIPT_BOX_NO_INTERSECTION = -1,
        VSCRIPT_BOX_LEFT,
        VSCRIPT_BOX_RIGHT,
        VSCRIPT_BOX_FRONT,
        VSCRIPT_BOX_BACK,
        VSCRIPT_BOX_BOTTOM,
        VSCRIPT_BOX_TOP
    };


    class CVisualScriptRenderer
    {
        protected:

            std::vector<CDebugRay> rays;

            void adjust_selection_color(int orient, int index, CScriptNode *node);

            void renderbox(CScriptNode *node, int orient);
            void renderboxoutline(vec p);
            void renderboxhelplines(vec p);

        public:

            CVisualScriptRenderer();
            ~CVisualScriptRenderer();

            void start_rendering();
            void render_debug_rays();
            void end_rendering();
    };
};
};


#endif