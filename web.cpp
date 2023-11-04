#include "emp/web/web.hpp"
#include "Org.h"
#include "World.h"
#include "emp/math/Random.hpp"
#include "emp/web/Animate.hpp"

emp::web::Document doc{"target"};

class AEAnimator : public emp::web::Animate {

    // arena width and height
    const int num_h_boxes = 10;
    const int num_w_boxes = 10;
    const double RECT_SIDE = 10;
    const double width{num_w_boxes * RECT_SIDE};
    const double height{num_h_boxes * RECT_SIDE};

    emp::web::Canvas canvas{width, height, "canvas"};
    emp::Random random{5};
    OrgWorld world{random};

  public:
    AEAnimator() {
        // shove canvas into the div
        // along with a control button
        doc << canvas;
        doc << GetToggleButton("Toggle");
        doc << GetStepButton("Step");
        world.SetPopStruct_Grid(num_w_boxes, num_h_boxes);
        Organism* new_org = new Organism(&random);
        world.Inject(*new_org);
        world.Resize(10, 10);
        
    }

    void DoFrame() override {
        canvas.Clear();
        world.Update();
        int org_num = 0;
        for (int x = 0; x < num_w_boxes; x++) {
            for (int y = 0; y < num_h_boxes; y++) {
                if (world.IsOccupied(org_num)) {
                    canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE,
                                RECT_SIDE, "black", "black");
                } else {
                    canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE,
                                RECT_SIDE, "white", "black");
                }
                org_num++;
            }
        }
    }
};

AEAnimator animator;

int main() {

    animator.Step();
}