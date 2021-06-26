#include "aux_macro.h"
#include "../malloc_3.cpp"
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
                        PRINT_POINTER(smalloc(175););
printStats();
void* p0 = last_address;
PRINT_POINTER(smalloc(235););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p1,245););
printStats();
void* p2 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p3 = last_address;
PRINT_POINTER(srealloc(p3,26););
printStats();
void* p4 = last_address;
PRINT_POINTER(srealloc(p2,161););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p5););
printStats();
PRINT_POINTER(scalloc(123,200););
printStats();
void* p6 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(smalloc(206););
printStats();
void* p7 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
DEBUG_PRINT(sfree(p7););
printStats();
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(smalloc(101););
printStats();
void* p8 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(smalloc(140););
printStats();
void* p9 = last_address;
PRINT_POINTER(srealloc(p9,39););
printStats();
void* p10 = last_address;
PRINT_POINTER(smalloc(13););
printStats();
void* p11 = last_address;
PRINT_POINTER(srealloc(p10,160););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(106,66););
printStats();
void* p13 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
DEBUG_PRINT(sfree(p12););
printStats();
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(scalloc(27,54););
printStats();
void* p14 = last_address;
PRINT_POINTER(srealloc(p14,38););
printStats();
void* p15 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p16 = last_address;
PRINT_POINTER(scalloc(62,70););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p19 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p20 = last_address;
PRINT_POINTER(scalloc(67,43););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(186,69););
printStats();
void* p22 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p23 = last_address;
PRINT_POINTER(scalloc(91,33););
printStats();
void* p24 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p26 = last_address;
PRINT_POINTER(scalloc(228,90););
printStats();
void* p27 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(scalloc(228,120););
printStats();
void* p28 = last_address;
PRINT_POINTER(srealloc(p22,198););
printStats();
void* p29 = last_address;
PRINT_POINTER(scalloc(232,65););
printStats();
void* p30 = last_address;
PRINT_POINTER(srealloc(p27,27););
printStats();
void* p31 = last_address;
PRINT_POINTER(scalloc(31,186););
printStats();
void* p32 = last_address;
PRINT_POINTER(smalloc(209););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p16););
printStats();
PRINT_POINTER(smalloc(173););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p18););
printStats();
PRINT_POINTER(srealloc(p33,17););
printStats();
void* p35 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(scalloc(200,156););
printStats();
void* p36 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p37 = last_address;
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(scalloc(207,10););
printStats();
void* p38 = last_address;
DEBUG_PRINT(sfree(p25););
printStats();
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(smalloc(101););
printStats();
void* p39 = last_address;
PRINT_POINTER(scalloc(82,189););
printStats();
void* p40 = last_address;
PRINT_POINTER(scalloc(158,182););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p19,24););
printStats();
void* p42 = last_address;
PRINT_POINTER(srealloc(p37,160););
printStats();
void* p43 = last_address;
DEBUG_PRINT(sfree(p41););
printStats();
DEBUG_PRINT(sfree(p28););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(scalloc(115,25););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p44,108););
printStats();
void* p45 = last_address;
PRINT_POINTER(scalloc(121,88););
printStats();
void* p46 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(smalloc(171););
printStats();
void* p47 = last_address;
PRINT_POINTER(srealloc(p30,145););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(132,53););
printStats();
void* p49 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
PRINT_POINTER(srealloc(p49,127););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(48,112););
printStats();
void* p51 = last_address;
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(srealloc(p39,107););
printStats();
void* p52 = last_address;
PRINT_POINTER(smalloc(159););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(177,99););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(6,37););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(181,28););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(105,136););
printStats();
void* p57 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(srealloc(p38,10););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(87,170););
printStats();
void* p59 = last_address;
PRINT_POINTER(smalloc(140););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p48,29););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p62 = last_address;
PRINT_POINTER(scalloc(136,117););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(203,0););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p42,247););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p21,95););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p54,150););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(192););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(86););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(10,115););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(scalloc(113,185););
printStats();
void* p72 = last_address;
PRINT_POINTER(smalloc(243););
printStats();
void* p73 = last_address;
PRINT_POINTER(smalloc(232););
printStats();
void* p74 = last_address;
PRINT_POINTER(smalloc(3););
printStats();
void* p75 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p76 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(srealloc(p74,177););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(smalloc(229););
printStats();
void* p78 = last_address;
PRINT_POINTER(scalloc(74,158););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p80 = last_address;
PRINT_POINTER(scalloc(87,213););
printStats();
void* p81 = last_address;
PRINT_POINTER(srealloc(p79,125););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p66,148););
printStats();
void* p84 = last_address;
PRINT_POINTER(srealloc(p68,53););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p69););
printStats();
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(scalloc(195,155););
printStats();
void* p86 = last_address;
PRINT_POINTER(scalloc(56,82););
printStats();
void* p87 = last_address;
PRINT_POINTER(srealloc(p65,5););
printStats();
void* p88 = last_address;
PRINT_POINTER(scalloc(10,199););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(205););
printStats();
void* p90 = last_address;
PRINT_POINTER(srealloc(p87,158););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(scalloc(25,169););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p75,219););
printStats();
void* p93 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(smalloc(100););
printStats();
void* p94 = last_address;
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(scalloc(83,232););
printStats();
void* p95 = last_address;
PRINT_POINTER(scalloc(89,119););
printStats();
void* p96 = last_address;
DEBUG_PRINT(sfree(p51););
printStats();
PRINT_POINTER(srealloc(p47,107););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(149,90););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p73););
printStats();
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(srealloc(p83,232););
printStats();
void* p99 = last_address;
PRINT_POINTER(scalloc(131,66););
printStats();
void* p100 = last_address;
PRINT_POINTER(srealloc(p56,12););
printStats();
void* p101 = last_address;
PRINT_POINTER(srealloc(p63,3););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p52,53););
printStats();
void* p103 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(54,139););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p106 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(srealloc(p80,168););
printStats();
void* p107 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p108 = last_address;
PRINT_POINTER(smalloc(236););
printStats();
void* p109 = last_address;
PRINT_POINTER(srealloc(p90,1););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p71,85););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
PRINT_POINTER(srealloc(p93,53););
printStats();
void* p112 = last_address;
PRINT_POINTER(scalloc(67,221););
printStats();
void* p113 = last_address;
PRINT_POINTER(srealloc(p89,87););
printStats();
void* p114 = last_address;
PRINT_POINTER(scalloc(114,165););
printStats();
void* p115 = last_address;
PRINT_POINTER(scalloc(48,53););
printStats();
void* p116 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(srealloc(p95,26););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
PRINT_POINTER(srealloc(p94,142););
printStats();
void* p118 = last_address;
PRINT_POINTER(scalloc(247,199););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(srealloc(p119,8););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(124););
printStats();
void* p121 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
DEBUG_PRINT(sfree(p85););
printStats();
DEBUG_PRINT(sfree(p102););
printStats();
PRINT_POINTER(srealloc(p97,94););
printStats();
void* p122 = last_address;
PRINT_POINTER(scalloc(50,129););
printStats();
void* p123 = last_address;
PRINT_POINTER(scalloc(35,224););
printStats();
void* p124 = last_address;
PRINT_POINTER(srealloc(p55,17););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p126 = last_address;
PRINT_POINTER(srealloc(p81,8););
printStats();
void* p127 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(scalloc(164,202););
printStats();
void* p128 = last_address;
DEBUG_PRINT(sfree(p114););
printStats();
PRINT_POINTER(smalloc(193););
printStats();
void* p129 = last_address;
PRINT_POINTER(smalloc(77););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(227,66););
printStats();
void* p131 = last_address;
PRINT_POINTER(scalloc(141,130););
printStats();
void* p132 = last_address;
PRINT_POINTER(scalloc(44,72););
printStats();
void* p133 = last_address;
PRINT_POINTER(smalloc(91););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(srealloc(p133,248););
printStats();
void* p135 = last_address;
PRINT_POINTER(scalloc(230,231););
printStats();
void* p136 = last_address;
PRINT_POINTER(scalloc(219,157););
printStats();
void* p137 = last_address;
PRINT_POINTER(smalloc(244););
printStats();
void* p138 = last_address;
PRINT_POINTER(scalloc(163,231););
printStats();
void* p139 = last_address;
PRINT_POINTER(srealloc(p122,183););
printStats();
void* p140 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p141 = last_address;
PRINT_POINTER(scalloc(26,197););
printStats();
void* p142 = last_address;
DEBUG_PRINT(sfree(p108););
printStats();
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(srealloc(p99,110););
printStats();
void* p143 = last_address;
DEBUG_PRINT(sfree(p138););
printStats();
PRINT_POINTER(srealloc(p86,176););
printStats();
void* p144 = last_address;
DEBUG_PRINT(sfree(p137););
printStats();
DEBUG_PRINT(sfree(p82););
printStats();
PRINT_POINTER(scalloc(211,205););
printStats();
void* p145 = last_address;
PRINT_POINTER(scalloc(180,225););
printStats();
void* p146 = last_address;
PRINT_POINTER(scalloc(241,228););
printStats();
void* p147 = last_address;
PRINT_POINTER(srealloc(p123,131););
printStats();
void* p148 = last_address;
PRINT_POINTER(srealloc(p58,234););
printStats();
void* p149 = last_address;
PRINT_POINTER(srealloc(p118,216););
printStats();
void* p150 = last_address;
DEBUG_PRINT(sfree(p129););
printStats();
PRINT_POINTER(srealloc(p113,85););
printStats();
void* p151 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p78,108););
printStats();
void* p153 = last_address;
PRINT_POINTER(smalloc(236););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p149););
printStats();
DEBUG_PRINT(sfree(p130););
printStats();
DEBUG_PRINT(sfree(p131););
printStats();
PRINT_POINTER(scalloc(168,17););
printStats();
void* p155 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p156 = last_address;
}
