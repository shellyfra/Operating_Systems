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
                        PRINT_POINTER(scalloc(163,54););
printStats();
void* p0 = last_address;
PRINT_POINTER(smalloc(58););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p0,68););
printStats();
void* p2 = last_address;
PRINT_POINTER(scalloc(138,128););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p4 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p5););
printStats();
PRINT_POINTER(scalloc(246,80););
printStats();
void* p6 = last_address;
PRINT_POINTER(srealloc(p6,180););
printStats();
void* p7 = last_address;
PRINT_POINTER(srealloc(p3,191););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p7,233););
printStats();
void* p9 = last_address;
PRINT_POINTER(scalloc(148,11););
printStats();
void* p10 = last_address;
PRINT_POINTER(smalloc(85););
printStats();
void* p11 = last_address;
PRINT_POINTER(scalloc(82,129););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(114,49););
printStats();
void* p13 = last_address;
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(smalloc(197););
printStats();
void* p14 = last_address;
PRINT_POINTER(scalloc(119,60););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p13,140););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p8,89););
printStats();
void* p17 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(srealloc(p15,117););
printStats();
void* p18 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(scalloc(245,240););
printStats();
void* p19 = last_address;
PRINT_POINTER(scalloc(6,41););
printStats();
void* p20 = last_address;
PRINT_POINTER(srealloc(p14,99););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(210,196););
printStats();
void* p22 = last_address;
PRINT_POINTER(scalloc(158,184););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p10););
printStats();
DEBUG_PRINT(sfree(p19););
printStats();
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(scalloc(158,100););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(239,246););
printStats();
void* p25 = last_address;
PRINT_POINTER(scalloc(99,240););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p26,68););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(168,53););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(scalloc(18,0););
printStats();
void* p29 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(87,195););
printStats();
void* p31 = last_address;
PRINT_POINTER(srealloc(p28,53););
printStats();
void* p32 = last_address;
PRINT_POINTER(smalloc(90););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
DEBUG_PRINT(sfree(p27););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(srealloc(p32,17););
printStats();
void* p34 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p35 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p36 = last_address;
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(srealloc(p16,240););
printStats();
void* p37 = last_address;
PRINT_POINTER(srealloc(p11,46););
printStats();
void* p38 = last_address;
PRINT_POINTER(scalloc(112,237););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p21,71););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(65,27););
printStats();
void* p42 = last_address;
PRINT_POINTER(scalloc(149,209););
printStats();
void* p43 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p39,216););
printStats();
void* p45 = last_address;
PRINT_POINTER(scalloc(4,94););
printStats();
void* p46 = last_address;
DEBUG_PRINT(sfree(p38););
printStats();
PRINT_POINTER(smalloc(182););
printStats();
void* p47 = last_address;
PRINT_POINTER(srealloc(p36,67););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(190,172););
printStats();
void* p49 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(scalloc(123,5););
printStats();
void* p50 = last_address;
PRINT_POINTER(smalloc(191););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(202,230););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(188,208););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
PRINT_POINTER(smalloc(150););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(164,209););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(27););
printStats();
void* p57 = last_address;
PRINT_POINTER(srealloc(p40,142););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(177,138););
printStats();
void* p59 = last_address;
PRINT_POINTER(scalloc(193,124););
printStats();
void* p60 = last_address;
PRINT_POINTER(scalloc(124,105););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(138,69););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p61,201););
printStats();
void* p63 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(srealloc(p63,73););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(224,160););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p18,221););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p9,14););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(61););
printStats();
void* p68 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
PRINT_POINTER(scalloc(73,87););
printStats();
void* p69 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
PRINT_POINTER(smalloc(105););
printStats();
void* p70 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(scalloc(113,63););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(scalloc(212,21););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(135,146););
printStats();
void* p73 = last_address;
PRINT_POINTER(smalloc(59););
printStats();
void* p74 = last_address;
PRINT_POINTER(srealloc(p30,214););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(221,248););
printStats();
void* p76 = last_address;
PRINT_POINTER(scalloc(109,104););
printStats();
void* p77 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p78 = last_address;
PRINT_POINTER(srealloc(p41,161););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(198,215););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p62,103););
printStats();
void* p81 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p83 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p67););
printStats();
PRINT_POINTER(srealloc(p52,150););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(179););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(24,125););
printStats();
void* p88 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p89 = last_address;
PRINT_POINTER(scalloc(205,247););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p91 = last_address;
PRINT_POINTER(scalloc(212,168););
printStats();
void* p92 = last_address;
PRINT_POINTER(scalloc(73,146););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p46,21););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(smalloc(1););
printStats();
void* p96 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
}
