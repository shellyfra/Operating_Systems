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
                        PRINT_POINTER(scalloc(70,138););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,95););
printStats();
void* p1 = last_address;
PRINT_POINTER(smalloc(238););
printStats();
void* p2 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(srealloc(p1,30););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(246););
printStats();
void* p4 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(srealloc(p4,207););
printStats();
void* p5 = last_address;
PRINT_POINTER(srealloc(p5,113););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(107,76););
printStats();
void* p7 = last_address;
PRINT_POINTER(srealloc(p7,186););
printStats();
void* p8 = last_address;
PRINT_POINTER(smalloc(247););
printStats();
void* p9 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(scalloc(27,14););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p10,127););
printStats();
void* p11 = last_address;
PRINT_POINTER(scalloc(74,191););
printStats();
void* p12 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(166,189););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(srealloc(p12,241););
printStats();
void* p15 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p13,207););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(28););
printStats();
void* p17 = last_address;
PRINT_POINTER(srealloc(p16,125););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p18););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(smalloc(231););
printStats();
void* p20 = last_address;
PRINT_POINTER(scalloc(108,248););
printStats();
void* p21 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(smalloc(210););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(srealloc(p14,9););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p11,25););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(209,97););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p26,191););
printStats();
void* p27 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(scalloc(59,186););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(scalloc(14,243););
printStats();
void* p29 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p30 = last_address;
PRINT_POINTER(srealloc(p29,151););
printStats();
void* p31 = last_address;
PRINT_POINTER(scalloc(87,27););
printStats();
void* p32 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(smalloc(0););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
PRINT_POINTER(scalloc(235,171););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p34,209););
printStats();
void* p35 = last_address;
PRINT_POINTER(smalloc(12););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p25,178););
printStats();
void* p37 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(143););
printStats();
void* p38 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
PRINT_POINTER(srealloc(p36,11););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p41,60););
printStats();
void* p42 = last_address;
PRINT_POINTER(srealloc(p40,191););
printStats();
void* p43 = last_address;
PRINT_POINTER(scalloc(77,67););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(84););
printStats();
void* p45 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p46 = last_address;
PRINT_POINTER(srealloc(p39,54););
printStats();
void* p47 = last_address;
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(srealloc(p38,245););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p35,85););
printStats();
void* p49 = last_address;
PRINT_POINTER(srealloc(p30,227););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p42,231););
printStats();
void* p51 = last_address;
PRINT_POINTER(srealloc(p44,208););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(scalloc(59,241););
printStats();
void* p53 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(srealloc(p53,167););
printStats();
void* p54 = last_address;
PRINT_POINTER(srealloc(p51,117););
printStats();
void* p55 = last_address;
PRINT_POINTER(smalloc(106););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p57 = last_address;
PRINT_POINTER(scalloc(147,178););
printStats();
void* p58 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(srealloc(p58,200););
printStats();
void* p60 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
PRINT_POINTER(srealloc(p60,49););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(143););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p56,110););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p59,170););
printStats();
void* p64 = last_address;
PRINT_POINTER(srealloc(p63,71););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p65,87););
printStats();
void* p66 = last_address;
PRINT_POINTER(scalloc(130,233););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p55,10););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p70 = last_address;
PRINT_POINTER(srealloc(p45,124););
printStats();
void* p71 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(93,118););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p57,134););
printStats();
void* p74 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(scalloc(145,227););
printStats();
void* p75 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p76 = last_address;
PRINT_POINTER(scalloc(57,52););
printStats();
void* p77 = last_address;
PRINT_POINTER(scalloc(104,70););
printStats();
void* p78 = last_address;
PRINT_POINTER(smalloc(157););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(230););
printStats();
void* p80 = last_address;
DEBUG_PRINT(sfree(p78););
printStats();
PRINT_POINTER(srealloc(p66,230););
printStats();
void* p81 = last_address;
PRINT_POINTER(scalloc(63,159););
printStats();
void* p82 = last_address;
PRINT_POINTER(srealloc(p49,132););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p83););
printStats();
PRINT_POINTER(srealloc(p79,136););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(scalloc(83,36););
printStats();
void* p86 = last_address;
DEBUG_PRINT(sfree(p82););
printStats();
PRINT_POINTER(scalloc(244,25););
printStats();
void* p87 = last_address;
PRINT_POINTER(srealloc(p80,108););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p72,196););
printStats();
void* p89 = last_address;
PRINT_POINTER(scalloc(158,97););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p91 = last_address;
PRINT_POINTER(srealloc(p37,236););
printStats();
void* p92 = last_address;
PRINT_POINTER(scalloc(249,143););
printStats();
void* p93 = last_address;
PRINT_POINTER(srealloc(p69,138););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p91,54););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(srealloc(p89,133););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p75,69););
printStats();
void* p97 = last_address;
PRINT_POINTER(smalloc(235););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p92););
printStats();
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(smalloc(67););
printStats();
void* p99 = last_address;
PRINT_POINTER(smalloc(38););
printStats();
void* p100 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(scalloc(24,129););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p102 = last_address;
PRINT_POINTER(scalloc(54,51););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(131,205););
printStats();
void* p104 = last_address;
PRINT_POINTER(srealloc(p93,15););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p81,192););
printStats();
void* p106 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
PRINT_POINTER(srealloc(p86,60););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
PRINT_POINTER(scalloc(74,197););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(22,71););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(178,59););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p77,185););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p98););
printStats();
PRINT_POINTER(srealloc(p67,83););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p113 = last_address;
PRINT_POINTER(srealloc(p70,91););
printStats();
void* p114 = last_address;
PRINT_POINTER(smalloc(180););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p111,124););
printStats();
void* p116 = last_address;
PRINT_POINTER(scalloc(74,112););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(smalloc(128););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p114,152););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(smalloc(31););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(73););
printStats();
void* p121 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
DEBUG_PRINT(sfree(p100););
printStats();
PRINT_POINTER(smalloc(69););
printStats();
void* p122 = last_address;
PRINT_POINTER(srealloc(p90,46););
printStats();
void* p123 = last_address;
PRINT_POINTER(scalloc(76,220););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p88););
printStats();
PRINT_POINTER(smalloc(131););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(196););
printStats();
void* p126 = last_address;
PRINT_POINTER(smalloc(103););
printStats();
void* p127 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(smalloc(143););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(207,189););
printStats();
void* p129 = last_address;
PRINT_POINTER(srealloc(p105,32););
printStats();
void* p130 = last_address;
PRINT_POINTER(srealloc(p110,2););
printStats();
void* p131 = last_address;
PRINT_POINTER(smalloc(62););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(scalloc(68,5););
printStats();
void* p133 = last_address;
}