#include <flag.h>
#include <flag.c>
#include "aobaker.h"

int main(int argc, const char **argv)
{
    char const* outmesh = "result.obj";
    char const* atlas = "result.png";
    int sizehint = 32;
    int nsamples = 128;
    bool gbuffer = false;
    bool chartinfo = false;
    flag_usage("[options] input_mesh.obj");
    flag_string(&outmesh, "outmesh", "OBJ file to produce");
    flag_string(&atlas, "atlas", "PNG file to produce");
    flag_int(&sizehint, "sizehint", "Controls resolution of atlas");
    flag_int(&nsamples, "nsamples", "Quality of ambient occlusion");
    flag_bool(&gbuffer, "gbuffer", "Generate diagnostic images");
    flag_bool(&chartinfo, "ids", "Add a chart id to the alpha channel");
    flag_parse(argc, argv, "v" AOBAKER_VERSION, 1);
    char const* inmesh = flagset_singleton()->argv[0];
    return aobaker_bake(inmesh, outmesh, atlas, sizehint, nsamples, gbuffer,
        chartinfo);
}
