#include "aux_macro.h"
#include "../malloc_2.cpp"
#include <iostream>

void printStats()
                    {
                        std::cout << "_num_free_blocks: " << _num_free_blocks() << std::endl;
                        std::cout << "_num_free_bytes: " << _num_free_bytes() << std::endl;
                        std::cout << "_num_allocated_blocks: " << _num_allocated_blocks() << std::endl;
                        std::cout << "_num_allocated_bytes: " << _num_allocated_bytes() << std::endl;
                        std::cout << "_num_meta_data_bytes: " << _num_meta_data_bytes() << std::endl;
                        std::cout << "_size_meta_data: " << _size_meta_data() << std::endl;
                    }
                    int main()
                    {
                        PRINT_POINTER(smalloc(52););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,17););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(76,105););
printStats();
void* p2 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(srealloc(p1,8););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(87,75););
printStats();
void* p4 = last_address;
PRINT_POINTER(srealloc(p3,125););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p5,89););
printStats();
void* p6 = last_address;
PRINT_POINTER(smalloc(152););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(141,157););
printStats();
void* p8 = last_address;
PRINT_POINTER(scalloc(31,60););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p7,125););
printStats();
void* p11 = last_address;
PRINT_POINTER(scalloc(49,133););
printStats();
void* p12 = last_address;
PRINT_POINTER(smalloc(156););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p8,32););
printStats();
void* p14 = last_address;
PRINT_POINTER(srealloc(p10,121););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(74,216););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(50););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(223););
printStats();
void* p18 = last_address;
PRINT_POINTER(scalloc(154,69););
printStats();
void* p19 = last_address;
PRINT_POINTER(scalloc(114,22););
printStats();
void* p20 = last_address;
PRINT_POINTER(srealloc(p18,104););
printStats();
void* p21 = last_address;
PRINT_POINTER(srealloc(p14,180););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(smalloc(199););
printStats();
void* p23 = last_address;
PRINT_POINTER(scalloc(64,242););
printStats();
void* p24 = last_address;
PRINT_POINTER(srealloc(p16,247););
printStats();
void* p25 = last_address;
PRINT_POINTER(scalloc(56,138););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(222););
printStats();
void* p27 = last_address;
PRINT_POINTER(smalloc(82););
printStats();
void* p28 = last_address;
PRINT_POINTER(srealloc(p28,10););
printStats();
void* p29 = last_address;
PRINT_POINTER(smalloc(46););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(153,56););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(184););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(79,207););
printStats();
void* p33 = last_address;
PRINT_POINTER(smalloc(141););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p31,105););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p13,125););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p35,58););
printStats();
void* p37 = last_address;
PRINT_POINTER(scalloc(99,103););
printStats();
void* p38 = last_address;
PRINT_POINTER(scalloc(12,177););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(49););
printStats();
void* p40 = last_address;
PRINT_POINTER(srealloc(p25,204););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p24,162););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(srealloc(p32,69););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p30,104););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p39,195););
printStats();
void* p45 = last_address;
PRINT_POINTER(srealloc(p40,203););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(4););
printStats();
void* p47 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(smalloc(202););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p43,232););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(44,76););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p21,203););
printStats();
void* p51 = last_address;
PRINT_POINTER(scalloc(103,209););
printStats();
void* p52 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p53 = last_address;
PRINT_POINTER(srealloc(p29,178););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(scalloc(176,233););
printStats();
void* p55 = last_address;
PRINT_POINTER(srealloc(p46,121););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(242,101););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p52,177););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p57,243););
printStats();
void* p60 = last_address;
PRINT_POINTER(scalloc(38,98););
printStats();
void* p61 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(scalloc(150,75););
printStats();
void* p62 = last_address;
PRINT_POINTER(scalloc(235,78););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p20,199););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(224,183););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p17,196););
printStats();
void* p66 = last_address;
PRINT_POINTER(smalloc(68););
printStats();
void* p67 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
PRINT_POINTER(scalloc(27,48););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(181,155););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p70 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(srealloc(p42,99););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(82,107););
printStats();
void* p73 = last_address;
PRINT_POINTER(scalloc(135,43););
printStats();
void* p74 = last_address;
PRINT_POINTER(scalloc(61,63););
printStats();
void* p75 = last_address;
PRINT_POINTER(smalloc(184););
printStats();
void* p76 = last_address;
PRINT_POINTER(smalloc(23););
printStats();
void* p77 = last_address;
PRINT_POINTER(srealloc(p33,228););
printStats();
void* p78 = last_address;
PRINT_POINTER(smalloc(72););
printStats();
void* p79 = last_address;
PRINT_POINTER(srealloc(p65,223););
printStats();
void* p80 = last_address;
PRINT_POINTER(smalloc(68););
printStats();
void* p81 = last_address;
PRINT_POINTER(srealloc(p70,203););
printStats();
void* p82 = last_address;
PRINT_POINTER(srealloc(p49,119););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(scalloc(103,54););
printStats();
void* p84 = last_address;
PRINT_POINTER(srealloc(p59,157););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(srealloc(p83,215););
printStats();
void* p86 = last_address;
DEBUG_PRINT(sfree(p34););
printStats();
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(smalloc(30););
printStats();
void* p87 = last_address;
PRINT_POINTER(smalloc(191););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p47,208););
printStats();
void* p89 = last_address;
PRINT_POINTER(srealloc(p64,85););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p91 = last_address;
PRINT_POINTER(srealloc(p79,122););
printStats();
void* p92 = last_address;
PRINT_POINTER(smalloc(192););
printStats();
void* p93 = last_address;
PRINT_POINTER(scalloc(111,94););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p89,208););
printStats();
void* p95 = last_address;
PRINT_POINTER(srealloc(p51,59););
printStats();
void* p96 = last_address;
DEBUG_PRINT(sfree(p41););
printStats();
PRINT_POINTER(srealloc(p12,35););
printStats();
void* p97 = last_address;
PRINT_POINTER(smalloc(146););
printStats();
void* p98 = last_address;
PRINT_POINTER(smalloc(193););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p53,177););
printStats();
void* p100 = last_address;
PRINT_POINTER(smalloc(116););
printStats();
void* p101 = last_address;
PRINT_POINTER(srealloc(p88,177););
printStats();
void* p102 = last_address;
PRINT_POINTER(scalloc(100,194););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(149,6););
printStats();
void* p104 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(srealloc(p90,153););
printStats();
void* p105 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(scalloc(102,120););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(77,161););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(smalloc(230););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(108,237););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
}
