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
                        PRINT_POINTER(smalloc(221););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,105););
printStats();
void* p1 = last_address;
PRINT_POINTER(smalloc(141););
printStats();
void* p2 = last_address;
PRINT_POINTER(smalloc(59););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(40,41););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(150,205););
printStats();
void* p5 = last_address;
PRINT_POINTER(srealloc(p1,150););
printStats();
void* p6 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(scalloc(19,169););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(132,64););
printStats();
void* p8 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(scalloc(41,21););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(58););
printStats();
void* p10 = last_address;
DEBUG_PRINT(sfree(p7););
printStats();
PRINT_POINTER(scalloc(186,76););
printStats();
void* p11 = last_address;
PRINT_POINTER(srealloc(p9,98););
printStats();
void* p12 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(scalloc(148,116););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(205,93););
printStats();
void* p14 = last_address;
PRINT_POINTER(srealloc(p5,197););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p12,124););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p14););
printStats();
PRINT_POINTER(scalloc(88,57););
printStats();
void* p17 = last_address;
PRINT_POINTER(srealloc(p11,225););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(129););
printStats();
void* p19 = last_address;
PRINT_POINTER(srealloc(p13,85););
printStats();
void* p20 = last_address;
PRINT_POINTER(smalloc(77););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(150,204););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(srealloc(p10,35););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p18,135););
printStats();
void* p24 = last_address;
PRINT_POINTER(smalloc(132););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p15,73););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p24,80););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(224,109););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(smalloc(39););
printStats();
void* p29 = last_address;
DEBUG_PRINT(sfree(p16););
printStats();
PRINT_POINTER(smalloc(30););
printStats();
void* p30 = last_address;
PRINT_POINTER(srealloc(p19,63););
printStats();
void* p31 = last_address;
PRINT_POINTER(srealloc(p31,172););
printStats();
void* p32 = last_address;
DEBUG_PRINT(sfree(p30););
printStats();
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(srealloc(p32,171););
printStats();
void* p33 = last_address;
PRINT_POINTER(srealloc(p29,88););
printStats();
void* p34 = last_address;
PRINT_POINTER(smalloc(56););
printStats();
void* p35 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(smalloc(182););
printStats();
void* p36 = last_address;
PRINT_POINTER(scalloc(6,162););
printStats();
void* p37 = last_address;
PRINT_POINTER(scalloc(12,136););
printStats();
void* p38 = last_address;
PRINT_POINTER(srealloc(p38,68););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p25,105););
printStats();
void* p40 = last_address;
PRINT_POINTER(scalloc(116,73););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(79,245););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(srealloc(p35,197););
printStats();
void* p43 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p45 = last_address;
PRINT_POINTER(srealloc(p45,160););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(231););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p33,226););
printStats();
void* p49 = last_address;
PRINT_POINTER(srealloc(p43,66););
printStats();
void* p50 = last_address;
PRINT_POINTER(smalloc(3););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(246););
printStats();
void* p52 = last_address;
PRINT_POINTER(srealloc(p37,67););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(15,181););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(srealloc(p44,55););
printStats();
void* p55 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(srealloc(p51,216););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p57 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(srealloc(p48,79););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(203,17););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p56,85););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p40,123););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(201,80););
printStats();
void* p62 = last_address;
PRINT_POINTER(scalloc(229,36););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p41,184););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p60,181););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(smalloc(94););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(126););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(28,236););
printStats();
void* p69 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(smalloc(150););
printStats();
void* p70 = last_address;
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(srealloc(p61,107););
printStats();
void* p71 = last_address;
PRINT_POINTER(scalloc(84,237););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(srealloc(p70,112););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p67,182););
printStats();
void* p74 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(6,142););
printStats();
void* p76 = last_address;
PRINT_POINTER(srealloc(p74,105););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(smalloc(118););
printStats();
void* p78 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p79 = last_address;
PRINT_POINTER(srealloc(p23,156););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p27,89););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(srealloc(p81,107););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(smalloc(94););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p82,142););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p85 = last_address;
PRINT_POINTER(scalloc(228,224););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(82,75););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p22,24););
printStats();
void* p89 = last_address;
DEBUG_PRINT(sfree(p86););
printStats();
PRINT_POINTER(scalloc(122,155););
printStats();
void* p90 = last_address;
PRINT_POINTER(scalloc(230,114););
printStats();
void* p91 = last_address;
PRINT_POINTER(scalloc(187,233););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p69,148););
printStats();
void* p93 = last_address;
PRINT_POINTER(srealloc(p73,175););
printStats();
void* p94 = last_address;
PRINT_POINTER(smalloc(56););
printStats();
void* p95 = last_address;
PRINT_POINTER(scalloc(159,63););
printStats();
void* p96 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(srealloc(p80,167););
printStats();
void* p97 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p98 = last_address;
PRINT_POINTER(scalloc(133,218););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p98,208););
printStats();
void* p100 = last_address;
PRINT_POINTER(srealloc(p92,87););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(27););
printStats();
void* p102 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(scalloc(98,148););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(72,2););
printStats();
void* p104 = last_address;
PRINT_POINTER(srealloc(p71,126););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p87,152););
printStats();
void* p106 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(srealloc(p85,182););
printStats();
void* p107 = last_address;
PRINT_POINTER(scalloc(197,86););
printStats();
void* p108 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p88););
printStats();
PRINT_POINTER(smalloc(196););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p110,72););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p84,156););
printStats();
void* p112 = last_address;
DEBUG_PRINT(sfree(p83););
printStats();
PRINT_POINTER(srealloc(p57,52););
printStats();
void* p113 = last_address;
PRINT_POINTER(srealloc(p91,104););
printStats();
void* p114 = last_address;
DEBUG_PRINT(sfree(p113););
printStats();
PRINT_POINTER(scalloc(238,17););
printStats();
void* p115 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(scalloc(154,152););
printStats();
void* p116 = last_address;
PRINT_POINTER(scalloc(125,69););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p94););
printStats();
PRINT_POINTER(smalloc(116););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p96,160););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
PRINT_POINTER(smalloc(232););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(65););
printStats();
void* p121 = last_address;
PRINT_POINTER(smalloc(86););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(smalloc(32););
printStats();
void* p123 = last_address;
DEBUG_PRINT(sfree(p108););
printStats();
PRINT_POINTER(srealloc(p58,3););
printStats();
void* p124 = last_address;
PRINT_POINTER(smalloc(179););
printStats();
void* p125 = last_address;
PRINT_POINTER(srealloc(p125,245););
printStats();
void* p126 = last_address;
PRINT_POINTER(scalloc(202,51););
printStats();
void* p127 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
DEBUG_PRINT(sfree(p126););
printStats();
PRINT_POINTER(scalloc(143,176););
printStats();
void* p128 = last_address;
PRINT_POINTER(smalloc(188););
printStats();
void* p129 = last_address;
PRINT_POINTER(scalloc(70,199););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(186,202););
printStats();
void* p131 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(scalloc(231,98););
printStats();
void* p132 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p97,93););
printStats();
void* p134 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p135 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(srealloc(p135,92););
printStats();
void* p136 = last_address;
PRINT_POINTER(scalloc(180,77););
printStats();
void* p137 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(scalloc(111,30););
printStats();
void* p138 = last_address;
PRINT_POINTER(srealloc(p134,49););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(80););
printStats();
void* p140 = last_address;
PRINT_POINTER(smalloc(132););
printStats();
void* p141 = last_address;
PRINT_POINTER(scalloc(227,229););
printStats();
void* p142 = last_address;
PRINT_POINTER(scalloc(134,83););
printStats();
void* p143 = last_address;
PRINT_POINTER(scalloc(4,86););
printStats();
void* p144 = last_address;
PRINT_POINTER(srealloc(p128,148););
printStats();
void* p145 = last_address;
PRINT_POINTER(scalloc(44,230););
printStats();
void* p146 = last_address;
PRINT_POINTER(scalloc(28,116););
printStats();
void* p147 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
DEBUG_PRINT(sfree(p114););
printStats();
DEBUG_PRINT(sfree(p133););
printStats();
PRINT_POINTER(scalloc(249,201););
printStats();
void* p148 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(scalloc(104,249););
printStats();
void* p149 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p151 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
PRINT_POINTER(scalloc(9,232););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p151,47););
printStats();
void* p153 = last_address;
PRINT_POINTER(scalloc(195,43););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(scalloc(20,183););
printStats();
void* p155 = last_address;
PRINT_POINTER(scalloc(195,192););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
PRINT_POINTER(smalloc(22););
printStats();
void* p157 = last_address;
PRINT_POINTER(srealloc(p130,132););
printStats();
void* p158 = last_address;
PRINT_POINTER(srealloc(p158,76););
printStats();
void* p159 = last_address;
PRINT_POINTER(srealloc(p124,162););
printStats();
void* p160 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p161 = last_address;
}
