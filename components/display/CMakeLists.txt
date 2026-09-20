file(GLOB_RECURSE UI "./ui/*.c")
file(GLOB_RECURSE IMGS "./ui/*.c")



idf_component_register(SRCS ${UI} ${IMGS} "display.c" "lvgl_port.c" "waveshare_rgb_lcd_port.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_lcd "lvgl")


idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
