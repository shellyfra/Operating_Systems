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
                        PRINT_POINTER(smalloc(218););
printStats();
void* p0 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(13,112););
printStats();
void* p2 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(scalloc(34,144););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(170,160););
printStats();
void* p4 = last_address;
PRINT_POINTER(srealloc(p1,2););
printStats();
void* p5 = last_address;
PRINT_POINTER(scalloc(84,224););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(190,15););
printStats();
void* p7 = last_address;
PRINT_POINTER(srealloc(p5,20););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p3,82););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(111););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p9,108););
printStats();
void* p11 = last_address;
PRINT_POINTER(scalloc(109,76););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(150,249););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p8,126););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(smalloc(196););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(22,2););
printStats();
void* p16 = last_address;
PRINT_POINTER(scalloc(216,173););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(28););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(srealloc(p14,74););
printStats();
void* p20 = last_address;
PRINT_POINTER(srealloc(p20,144););
printStats();
void* p21 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p22 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p18,84););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(193,64););
printStats();
void* p25 = last_address;
PRINT_POINTER(scalloc(171,96););
printStats();
void* p26 = last_address;
PRINT_POINTER(scalloc(3,30););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(175,145););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(scalloc(44,75););
printStats();
void* p29 = last_address;
PRINT_POINTER(scalloc(193,158););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p31 = last_address;
DEBUG_PRINT(sfree(p10););
printStats();
PRINT_POINTER(smalloc(26););
printStats();
void* p32 = last_address;
PRINT_POINTER(srealloc(p24,33););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p16););
printStats();
DEBUG_PRINT(sfree(p7););
printStats();
PRINT_POINTER(scalloc(211,84););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(smalloc(71););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p34,135););
printStats();
void* p36 = last_address;
PRINT_POINTER(scalloc(148,27););
printStats();
void* p37 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
DEBUG_PRINT(sfree(p12););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(scalloc(83,237););
printStats();
void* p38 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p33,189););
printStats();
void* p40 = last_address;
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(smalloc(214););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(154,202););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(scalloc(53,121););
printStats();
void* p43 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(scalloc(111,153););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p45 = last_address;
PRINT_POINTER(srealloc(p38,239););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(10););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p48 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(199,188););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p40,228););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(183,160););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(27,237););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(smalloc(77););
printStats();
void* p55 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p56 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(scalloc(29,103););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p58 = last_address;
DEBUG_PRINT(sfree(p58););
printStats();
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(scalloc(137,74););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p45,165););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p59,11););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p62 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(211,147););
printStats();
void* p64 = last_address;
PRINT_POINTER(srealloc(p25,193););
printStats();
void* p65 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
DEBUG_PRINT(sfree(p63););
printStats();
PRINT_POINTER(srealloc(p61,90););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p29,115););
printStats();
void* p67 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
PRINT_POINTER(scalloc(103,231););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(193););
printStats();
void* p69 = last_address;
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(scalloc(182,117););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(26,24););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(srealloc(p64,142););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(123,203););
printStats();
void* p73 = last_address;
PRINT_POINTER(smalloc(246););
printStats();
void* p74 = last_address;
PRINT_POINTER(smalloc(152););
printStats();
void* p75 = last_address;
PRINT_POINTER(srealloc(p66,177););
printStats();
void* p76 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p77 = last_address;
PRINT_POINTER(scalloc(123,70););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(srealloc(p77,46););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(194););
printStats();
void* p80 = last_address;
PRINT_POINTER(scalloc(196,10););
printStats();
void* p81 = last_address;
PRINT_POINTER(srealloc(p50,185););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(scalloc(200,220););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p83,66););
printStats();
void* p84 = last_address;
PRINT_POINTER(scalloc(51,107););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p67););
printStats();
PRINT_POINTER(smalloc(24););
printStats();
void* p86 = last_address;
PRINT_POINTER(srealloc(p31,175););
printStats();
void* p87 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p88 = last_address;
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(scalloc(196,151););
printStats();
void* p89 = last_address;
PRINT_POINTER(srealloc(p68,173););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(6););
printStats();
void* p91 = last_address;
PRINT_POINTER(smalloc(119););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p87,211););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(36,187););
printStats();
void* p95 = last_address;
PRINT_POINTER(srealloc(p4,157););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(56,24););
printStats();
void* p97 = last_address;
PRINT_POINTER(srealloc(p95,169););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p80,85););
printStats();
void* p99 = last_address;
PRINT_POINTER(scalloc(134,229););
printStats();
void* p100 = last_address;
PRINT_POINTER(srealloc(p60,164););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(78););
printStats();
void* p102 = last_address;
PRINT_POINTER(smalloc(74););
printStats();
void* p103 = last_address;
PRINT_POINTER(smalloc(71););
printStats();
void* p104 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(177););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(15,95););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p84););
printStats();
PRINT_POINTER(scalloc(87,202););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p105,140););
printStats();
void* p109 = last_address;
PRINT_POINTER(srealloc(p107,137););
printStats();
void* p110 = last_address;
PRINT_POINTER(smalloc(136););
printStats();
void* p111 = last_address;
PRINT_POINTER(scalloc(205,12););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(236););
printStats();
void* p113 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p114 = last_address;
PRINT_POINTER(srealloc(p47,207););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p53,235););
printStats();
void* p116 = last_address;
}
