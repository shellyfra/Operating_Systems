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
                        PRINT_POINTER(smalloc(211););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(smalloc(13););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(174,119););
printStats();
void* p2 = last_address;
PRINT_POINTER(srealloc(p2,177););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(56,237););
printStats();
void* p4 = last_address;
PRINT_POINTER(srealloc(p1,235););
printStats();
void* p5 = last_address;
PRINT_POINTER(scalloc(99,18););
printStats();
void* p6 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(smalloc(13););
printStats();
void* p7 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(smalloc(172););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p5,32););
printStats();
void* p9 = last_address;
PRINT_POINTER(srealloc(p7,130););
printStats();
void* p10 = last_address;
PRINT_POINTER(scalloc(13,76););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(smalloc(99););
printStats();
void* p12 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p13 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(srealloc(p8,21););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(smalloc(33););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(212,13););
printStats();
void* p16 = last_address;
PRINT_POINTER(scalloc(69,249););
printStats();
void* p17 = last_address;
PRINT_POINTER(srealloc(p14,106););
printStats();
void* p18 = last_address;
DEBUG_PRINT(sfree(p10););
printStats();
PRINT_POINTER(srealloc(p15,144););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
DEBUG_PRINT(sfree(p19););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(srealloc(p18,149););
printStats();
void* p20 = last_address;
PRINT_POINTER(srealloc(p20,64););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(53,69););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
DEBUG_PRINT(sfree(p16););
printStats();
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(smalloc(117););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(63););
printStats();
void* p24 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(smalloc(12););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p25,23););
printStats();
void* p26 = last_address;
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(smalloc(1););
printStats();
void* p27 = last_address;
PRINT_POINTER(srealloc(p27,105););
printStats();
void* p28 = last_address;
PRINT_POINTER(srealloc(p28,96););
printStats();
void* p29 = last_address;
PRINT_POINTER(scalloc(5,153););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(35,114););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(40););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(88,65););
printStats();
void* p33 = last_address;
PRINT_POINTER(scalloc(176,207););
printStats();
void* p34 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p35 = last_address;
PRINT_POINTER(scalloc(190,39););
printStats();
void* p36 = last_address;
PRINT_POINTER(smalloc(153););
printStats();
void* p37 = last_address;
PRINT_POINTER(scalloc(188,72););
printStats();
void* p38 = last_address;
PRINT_POINTER(scalloc(112,162););
printStats();
void* p39 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
PRINT_POINTER(srealloc(p35,194););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(20););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p39,172););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(smalloc(83););
printStats();
void* p43 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
PRINT_POINTER(smalloc(207););
printStats();
void* p44 = last_address;
PRINT_POINTER(scalloc(30,121););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(smalloc(165););
printStats();
void* p46 = last_address;
PRINT_POINTER(scalloc(31,193););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(10,173););
printStats();
void* p49 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
DEBUG_PRINT(sfree(p44););
printStats();
DEBUG_PRINT(sfree(p41););
printStats();
PRINT_POINTER(scalloc(155,76););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(248,105););
printStats();
void* p51 = last_address;
DEBUG_PRINT(sfree(p51););
printStats();
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(smalloc(151););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(249,81););
printStats();
void* p53 = last_address;
PRINT_POINTER(smalloc(225););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(110,227););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(235,77););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(121,91););
printStats();
void* p57 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(scalloc(248,25););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p43,86););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
PRINT_POINTER(smalloc(132););
printStats();
void* p60 = last_address;
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(srealloc(p46,83););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(0););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p60,11););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(161,109););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(50,217););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p66 = last_address;
PRINT_POINTER(scalloc(213,219););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p58,209););
printStats();
void* p68 = last_address;
PRINT_POINTER(srealloc(p64,156););
printStats();
void* p69 = last_address;
PRINT_POINTER(scalloc(58,27););
printStats();
void* p70 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(srealloc(p62,51););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p63););
printStats();
PRINT_POINTER(scalloc(112,205););
printStats();
void* p73 = last_address;
PRINT_POINTER(scalloc(185,187););
printStats();
void* p74 = last_address;
PRINT_POINTER(srealloc(p61,191););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(125,65););
printStats();
void* p76 = last_address;
PRINT_POINTER(srealloc(p38,81););
printStats();
void* p77 = last_address;
PRINT_POINTER(srealloc(p53,47););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(srealloc(p59,139););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(188,11););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p71,16););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p69););
printStats();
PRINT_POINTER(srealloc(p34,207););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p83 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p84 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
DEBUG_PRINT(sfree(p54););
printStats();
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(srealloc(p81,113););
printStats();
void* p85 = last_address;
PRINT_POINTER(srealloc(p77,180););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(48,19););
printStats();
void* p88 = last_address;
DEBUG_PRINT(sfree(p86););
printStats();
PRINT_POINTER(scalloc(185,174););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(16););
printStats();
void* p90 = last_address;
PRINT_POINTER(scalloc(239,210););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
PRINT_POINTER(srealloc(p49,231););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p65,75););
printStats();
void* p93 = last_address;
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(scalloc(140,134););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p91,148););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p30););
printStats();
PRINT_POINTER(scalloc(147,37););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(224,188););
printStats();
void* p97 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p76,47););
printStats();
void* p99 = last_address;
DEBUG_PRINT(sfree(p94););
printStats();
PRINT_POINTER(srealloc(p97,44););
printStats();
void* p100 = last_address;
DEBUG_PRINT(sfree(p88););
printStats();
PRINT_POINTER(srealloc(p80,182););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(12););
printStats();
void* p102 = last_address;
PRINT_POINTER(smalloc(140););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(195,71););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(174,209););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(74););
printStats();
void* p106 = last_address;
PRINT_POINTER(smalloc(36););
printStats();
void* p107 = last_address;
PRINT_POINTER(scalloc(173,128););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(240,234););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(235,196););
printStats();
void* p110 = last_address;
PRINT_POINTER(smalloc(222););
printStats();
void* p111 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p112 = last_address;
PRINT_POINTER(srealloc(p83,201););
printStats();
void* p113 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p114 = last_address;
PRINT_POINTER(scalloc(70,55););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p42,190););
printStats();
void* p116 = last_address;
PRINT_POINTER(srealloc(p116,229););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(239););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p67,146););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
PRINT_POINTER(srealloc(p96,94););
printStats();
void* p120 = last_address;
PRINT_POINTER(scalloc(192,139););
printStats();
void* p121 = last_address;
PRINT_POINTER(scalloc(44,65););
printStats();
void* p122 = last_address;
PRINT_POINTER(smalloc(168););
printStats();
void* p123 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p124 = last_address;
PRINT_POINTER(srealloc(p124,223););
printStats();
void* p125 = last_address;
PRINT_POINTER(srealloc(p82,221););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
DEBUG_PRINT(sfree(p110););
printStats();
DEBUG_PRINT(sfree(p108););
printStats();
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(scalloc(246,59););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(237,29););
printStats();
void* p129 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
DEBUG_PRINT(sfree(p128););
printStats();
PRINT_POINTER(smalloc(69););
printStats();
void* p130 = last_address;
PRINT_POINTER(smalloc(22););
printStats();
void* p131 = last_address;
PRINT_POINTER(scalloc(186,72););
printStats();
void* p132 = last_address;
PRINT_POINTER(smalloc(15););
printStats();
void* p133 = last_address;
DEBUG_PRINT(sfree(p126););
printStats();
PRINT_POINTER(srealloc(p133,168););
printStats();
void* p134 = last_address;
PRINT_POINTER(srealloc(p123,156););
printStats();
void* p135 = last_address;
DEBUG_PRINT(sfree(p120););
printStats();
PRINT_POINTER(srealloc(p68,48););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(247););
printStats();
void* p137 = last_address;
PRINT_POINTER(scalloc(195,70););
printStats();
void* p138 = last_address;
PRINT_POINTER(srealloc(p78,117););
printStats();
void* p139 = last_address;
DEBUG_PRINT(sfree(p84););
printStats();
PRINT_POINTER(smalloc(200););
printStats();
void* p140 = last_address;
DEBUG_PRINT(sfree(p113););
printStats();
PRINT_POINTER(srealloc(p119,36););
printStats();
void* p141 = last_address;
PRINT_POINTER(smalloc(181););
printStats();
void* p142 = last_address;
PRINT_POINTER(smalloc(230););
printStats();
void* p143 = last_address;
PRINT_POINTER(scalloc(47,151););
printStats();
void* p144 = last_address;
PRINT_POINTER(scalloc(68,101););
printStats();
void* p145 = last_address;
PRINT_POINTER(smalloc(200););
printStats();
void* p146 = last_address;
PRINT_POINTER(smalloc(77););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(227,212););
printStats();
void* p148 = last_address;
PRINT_POINTER(scalloc(3,179););
printStats();
void* p149 = last_address;
PRINT_POINTER(srealloc(p114,195););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p151 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p90,198););
printStats();
void* p153 = last_address;
PRINT_POINTER(smalloc(35););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p135););
printStats();
PRINT_POINTER(srealloc(p145,240););
printStats();
void* p155 = last_address;
PRINT_POINTER(scalloc(179,200););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
PRINT_POINTER(smalloc(25););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(166););
printStats();
void* p158 = last_address;
DEBUG_PRINT(sfree(p150););
printStats();
PRINT_POINTER(srealloc(p153,6););
printStats();
void* p159 = last_address;
PRINT_POINTER(scalloc(164,236););
printStats();
void* p160 = last_address;
PRINT_POINTER(scalloc(195,236););
printStats();
void* p161 = last_address;
PRINT_POINTER(smalloc(81););
printStats();
void* p162 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p163 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(scalloc(58,231););
printStats();
void* p164 = last_address;
DEBUG_PRINT(sfree(p118););
printStats();
DEBUG_PRINT(sfree(p132););
printStats();
DEBUG_PRINT(sfree(p138););
printStats();
PRINT_POINTER(srealloc(p100,238););
printStats();
void* p165 = last_address;
PRINT_POINTER(scalloc(114,170););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p162););
printStats();
PRINT_POINTER(scalloc(208,236););
printStats();
void* p167 = last_address;
PRINT_POINTER(scalloc(192,220););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(3,46););
printStats();
void* p169 = last_address;
DEBUG_PRINT(sfree(p161););
printStats();
DEBUG_PRINT(sfree(p166););
printStats();
PRINT_POINTER(srealloc(p107,205););
printStats();
void* p170 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p171 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(smalloc(53););
printStats();
void* p172 = last_address;
DEBUG_PRINT(sfree(p134););
printStats();
DEBUG_PRINT(sfree(p136););
printStats();
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(scalloc(66,18););
printStats();
void* p173 = last_address;
PRINT_POINTER(scalloc(211,169););
printStats();
void* p174 = last_address;
DEBUG_PRINT(sfree(p169););
printStats();
PRINT_POINTER(srealloc(p121,110););
printStats();
void* p175 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
PRINT_POINTER(smalloc(158););
printStats();
void* p176 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p177 = last_address;
DEBUG_PRINT(sfree(p173););
printStats();
PRINT_POINTER(smalloc(20););
printStats();
void* p178 = last_address;
DEBUG_PRINT(sfree(p165););
printStats();
DEBUG_PRINT(sfree(p79););
printStats();
DEBUG_PRINT(sfree(p160););
printStats();
PRINT_POINTER(srealloc(p129,80););
printStats();
void* p179 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p181 = last_address;
PRINT_POINTER(scalloc(150,207););
printStats();
void* p182 = last_address;
PRINT_POINTER(srealloc(p159,153););
printStats();
void* p183 = last_address;
DEBUG_PRINT(sfree(p130););
printStats();
DEBUG_PRINT(sfree(p148););
printStats();
PRINT_POINTER(srealloc(p183,45););
printStats();
void* p184 = last_address;
PRINT_POINTER(smalloc(145););
printStats();
void* p185 = last_address;
DEBUG_PRINT(sfree(p175););
printStats();
DEBUG_PRINT(sfree(p149););
printStats();
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(scalloc(112,54););
printStats();
void* p186 = last_address;
PRINT_POINTER(scalloc(224,230););
printStats();
void* p187 = last_address;
PRINT_POINTER(scalloc(137,97););
printStats();
void* p188 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p189 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
PRINT_POINTER(srealloc(p66,53););
printStats();
void* p190 = last_address;
PRINT_POINTER(smalloc(77););
printStats();
void* p191 = last_address;
PRINT_POINTER(scalloc(76,190););
printStats();
void* p192 = last_address;
PRINT_POINTER(smalloc(74););
printStats();
void* p193 = last_address;
PRINT_POINTER(smalloc(24););
printStats();
void* p194 = last_address;
DEBUG_PRINT(sfree(p176););
printStats();
PRINT_POINTER(smalloc(112););
printStats();
void* p195 = last_address;
PRINT_POINTER(srealloc(p144,128););
printStats();
void* p196 = last_address;
PRINT_POINTER(smalloc(243););
printStats();
void* p197 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p198 = last_address;
PRINT_POINTER(srealloc(p131,197););
printStats();
void* p199 = last_address;
PRINT_POINTER(srealloc(p170,192););
printStats();
void* p200 = last_address;
PRINT_POINTER(scalloc(71,70););
printStats();
void* p201 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p202 = last_address;
PRINT_POINTER(scalloc(136,170););
printStats();
void* p203 = last_address;
PRINT_POINTER(srealloc(p157,55););
printStats();
void* p204 = last_address;
PRINT_POINTER(srealloc(p142,69););
printStats();
void* p205 = last_address;
PRINT_POINTER(smalloc(12););
printStats();
void* p206 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p207 = last_address;
PRINT_POINTER(smalloc(28););
printStats();
void* p208 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p209 = last_address;
DEBUG_PRINT(sfree(p202););
printStats();
PRINT_POINTER(srealloc(p117,136););
printStats();
void* p210 = last_address;
DEBUG_PRINT(sfree(p184););
printStats();
DEBUG_PRINT(sfree(p177););
printStats();
PRINT_POINTER(srealloc(p193,248););
printStats();
void* p211 = last_address;
PRINT_POINTER(srealloc(p56,221););
printStats();
void* p212 = last_address;
DEBUG_PRINT(sfree(p196););
printStats();
PRINT_POINTER(smalloc(150););
printStats();
void* p213 = last_address;
DEBUG_PRINT(sfree(p199););
printStats();
DEBUG_PRINT(sfree(p147););
printStats();
PRINT_POINTER(srealloc(p189,189););
printStats();
void* p214 = last_address;
PRINT_POINTER(smalloc(139););
printStats();
void* p215 = last_address;
PRINT_POINTER(smalloc(165););
printStats();
void* p216 = last_address;
PRINT_POINTER(scalloc(112,167););
printStats();
void* p217 = last_address;
PRINT_POINTER(srealloc(p168,97););
printStats();
void* p218 = last_address;
PRINT_POINTER(srealloc(p207,231););
printStats();
void* p219 = last_address;
PRINT_POINTER(srealloc(p98,217););
printStats();
void* p220 = last_address;
DEBUG_PRINT(sfree(p191););
printStats();
DEBUG_PRINT(sfree(p154););
printStats();
PRINT_POINTER(srealloc(p111,41););
printStats();
void* p221 = last_address;
PRINT_POINTER(scalloc(92,0););
printStats();
void* p222 = last_address;
PRINT_POINTER(srealloc(p158,24););
printStats();
void* p223 = last_address;
DEBUG_PRINT(sfree(p194););
printStats();
PRINT_POINTER(smalloc(131););
printStats();
void* p224 = last_address;
DEBUG_PRINT(sfree(p217););
printStats();
PRINT_POINTER(smalloc(202););
printStats();
void* p225 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(scalloc(80,38););
printStats();
void* p226 = last_address;
PRINT_POINTER(srealloc(p186,84););
printStats();
void* p227 = last_address;
DEBUG_PRINT(sfree(p156););
printStats();
DEBUG_PRINT(sfree(p206););
printStats();
DEBUG_PRINT(sfree(p72););
printStats();
PRINT_POINTER(srealloc(p215,90););
printStats();
void* p228 = last_address;
PRINT_POINTER(smalloc(215););
printStats();
void* p229 = last_address;
PRINT_POINTER(scalloc(185,73););
printStats();
void* p230 = last_address;
PRINT_POINTER(scalloc(234,85););
printStats();
void* p231 = last_address;
PRINT_POINTER(scalloc(128,197););
printStats();
void* p232 = last_address;
PRINT_POINTER(srealloc(p164,34););
printStats();
void* p233 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(smalloc(15););
printStats();
void* p234 = last_address;
PRINT_POINTER(scalloc(128,246););
printStats();
void* p235 = last_address;
PRINT_POINTER(scalloc(140,167););
printStats();
void* p236 = last_address;
DEBUG_PRINT(sfree(p188););
printStats();
PRINT_POINTER(srealloc(p205,159););
printStats();
void* p237 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p238 = last_address;
DEBUG_PRINT(sfree(p151););
printStats();
PRINT_POINTER(smalloc(154););
printStats();
void* p239 = last_address;
PRINT_POINTER(smalloc(163););
printStats();
void* p240 = last_address;
PRINT_POINTER(smalloc(141););
printStats();
void* p241 = last_address;
PRINT_POINTER(srealloc(p182,245););
printStats();
void* p242 = last_address;
PRINT_POINTER(srealloc(p106,176););
printStats();
void* p243 = last_address;
DEBUG_PRINT(sfree(p220););
printStats();
PRINT_POINTER(smalloc(37););
printStats();
void* p244 = last_address;
PRINT_POINTER(srealloc(p235,236););
printStats();
void* p245 = last_address;
PRINT_POINTER(smalloc(74););
printStats();
void* p246 = last_address;
PRINT_POINTER(scalloc(184,75););
printStats();
void* p247 = last_address;
PRINT_POINTER(srealloc(p231,216););
printStats();
void* p248 = last_address;
DEBUG_PRINT(sfree(p190););
printStats();
PRINT_POINTER(srealloc(p172,150););
printStats();
void* p249 = last_address;
DEBUG_PRINT(sfree(p187););
printStats();
PRINT_POINTER(smalloc(129););
printStats();
void* p250 = last_address;
DEBUG_PRINT(sfree(p197););
printStats();
DEBUG_PRINT(sfree(p211););
printStats();
DEBUG_PRINT(sfree(p143););
printStats();
PRINT_POINTER(smalloc(181););
printStats();
void* p251 = last_address;
PRINT_POINTER(scalloc(240,42););
printStats();
void* p252 = last_address;
DEBUG_PRINT(sfree(p219););
printStats();
PRINT_POINTER(scalloc(243,81););
printStats();
void* p253 = last_address;
DEBUG_PRINT(sfree(p233););
printStats();
DEBUG_PRINT(sfree(p240););
printStats();
DEBUG_PRINT(sfree(p232););
printStats();
DEBUG_PRINT(sfree(p179););
printStats();
PRINT_POINTER(srealloc(p248,249););
printStats();
void* p254 = last_address;
PRINT_POINTER(scalloc(112,115););
printStats();
void* p255 = last_address;
DEBUG_PRINT(sfree(p208););
printStats();
PRINT_POINTER(srealloc(p226,95););
printStats();
void* p256 = last_address;
PRINT_POINTER(scalloc(216,112););
printStats();
void* p257 = last_address;
PRINT_POINTER(scalloc(36,92););
printStats();
void* p258 = last_address;
PRINT_POINTER(smalloc(200););
printStats();
void* p259 = last_address;
DEBUG_PRINT(sfree(p227););
printStats();
PRINT_POINTER(smalloc(51););
printStats();
void* p260 = last_address;
DEBUG_PRINT(sfree(p241););
printStats();
DEBUG_PRINT(sfree(p230););
printStats();
PRINT_POINTER(smalloc(110););
printStats();
void* p261 = last_address;
PRINT_POINTER(scalloc(159,12););
printStats();
void* p262 = last_address;
PRINT_POINTER(scalloc(174,199););
printStats();
void* p263 = last_address;
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(srealloc(p181,9););
printStats();
void* p264 = last_address;
PRINT_POINTER(smalloc(181););
printStats();
void* p265 = last_address;
PRINT_POINTER(smalloc(229););
printStats();
void* p266 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p267 = last_address;
PRINT_POINTER(scalloc(129,79););
printStats();
void* p268 = last_address;
DEBUG_PRINT(sfree(p213););
printStats();
DEBUG_PRINT(sfree(p263););
printStats();
PRINT_POINTER(smalloc(170););
printStats();
void* p269 = last_address;
PRINT_POINTER(srealloc(p247,16););
printStats();
void* p270 = last_address;
PRINT_POINTER(srealloc(p224,205););
printStats();
void* p271 = last_address;
PRINT_POINTER(srealloc(p75,50););
printStats();
void* p272 = last_address;
DEBUG_PRINT(sfree(p203););
printStats();
DEBUG_PRINT(sfree(p163););
printStats();
PRINT_POINTER(srealloc(p228,247););
printStats();
void* p273 = last_address;
PRINT_POINTER(srealloc(p255,191););
printStats();
void* p274 = last_address;
PRINT_POINTER(srealloc(p267,211););
printStats();
void* p275 = last_address;
PRINT_POINTER(scalloc(221,10););
printStats();
void* p276 = last_address;
PRINT_POINTER(scalloc(30,208););
printStats();
void* p277 = last_address;
PRINT_POINTER(srealloc(p271,191););
printStats();
void* p278 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p279 = last_address;
PRINT_POINTER(smalloc(47););
printStats();
void* p280 = last_address;
PRINT_POINTER(smalloc(22););
printStats();
void* p281 = last_address;
PRINT_POINTER(smalloc(190););
printStats();
void* p282 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p283 = last_address;
PRINT_POINTER(srealloc(p109,229););
printStats();
void* p284 = last_address;
PRINT_POINTER(srealloc(p272,72););
printStats();
void* p285 = last_address;
DEBUG_PRINT(sfree(p270););
printStats();
DEBUG_PRINT(sfree(p265););
printStats();
PRINT_POINTER(smalloc(37););
printStats();
void* p286 = last_address;
PRINT_POINTER(srealloc(p268,190););
printStats();
void* p287 = last_address;
PRINT_POINTER(scalloc(44,127););
printStats();
void* p288 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p289 = last_address;
DEBUG_PRINT(sfree(p212););
printStats();
PRINT_POINTER(scalloc(57,48););
printStats();
void* p290 = last_address;
PRINT_POINTER(srealloc(p171,115););
printStats();
void* p291 = last_address;
PRINT_POINTER(scalloc(224,118););
printStats();
void* p292 = last_address;
DEBUG_PRINT(sfree(p250););
printStats();
PRINT_POINTER(smalloc(41););
printStats();
void* p293 = last_address;
DEBUG_PRINT(sfree(p223););
printStats();
PRINT_POINTER(smalloc(52););
printStats();
void* p294 = last_address;
PRINT_POINTER(smalloc(63););
printStats();
void* p295 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p296 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p297 = last_address;
DEBUG_PRINT(sfree(p276););
printStats();
PRINT_POINTER(smalloc(107););
printStats();
void* p298 = last_address;
DEBUG_PRINT(sfree(p292););
printStats();
PRINT_POINTER(srealloc(p275,128););
printStats();
void* p299 = last_address;
PRINT_POINTER(srealloc(p236,187););
printStats();
void* p300 = last_address;
PRINT_POINTER(srealloc(p252,62););
printStats();
void* p301 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p302 = last_address;
PRINT_POINTER(srealloc(p291,74););
printStats();
void* p303 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p304 = last_address;
PRINT_POINTER(scalloc(157,238););
printStats();
void* p305 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p306 = last_address;
PRINT_POINTER(scalloc(212,111););
printStats();
void* p307 = last_address;
DEBUG_PRINT(sfree(p242););
printStats();
PRINT_POINTER(smalloc(149););
printStats();
void* p308 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p309 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
PRINT_POINTER(srealloc(p308,202););
printStats();
void* p310 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p311 = last_address;
PRINT_POINTER(srealloc(p289,14););
printStats();
void* p312 = last_address;
PRINT_POINTER(srealloc(p278,240););
printStats();
void* p313 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p314 = last_address;
PRINT_POINTER(srealloc(p137,209););
printStats();
void* p315 = last_address;
PRINT_POINTER(scalloc(96,94););
printStats();
void* p316 = last_address;
PRINT_POINTER(srealloc(p257,180););
printStats();
void* p317 = last_address;
DEBUG_PRINT(sfree(p239););
printStats();
DEBUG_PRINT(sfree(p141););
printStats();
DEBUG_PRINT(sfree(p316););
printStats();
PRINT_POINTER(srealloc(p167,79););
printStats();
void* p318 = last_address;
PRINT_POINTER(scalloc(52,93););
printStats();
void* p319 = last_address;
DEBUG_PRINT(sfree(p309););
printStats();
PRINT_POINTER(scalloc(228,140););
printStats();
void* p320 = last_address;
DEBUG_PRINT(sfree(p306););
printStats();
DEBUG_PRINT(sfree(p245););
printStats();
PRINT_POINTER(scalloc(84,200););
printStats();
void* p321 = last_address;
PRINT_POINTER(srealloc(p238,93););
printStats();
void* p322 = last_address;
PRINT_POINTER(scalloc(31,205););
printStats();
void* p323 = last_address;
PRINT_POINTER(scalloc(85,139););
printStats();
void* p324 = last_address;
DEBUG_PRINT(sfree(p155););
printStats();
PRINT_POINTER(scalloc(92,242););
printStats();
void* p325 = last_address;
DEBUG_PRINT(sfree(p303););
printStats();
PRINT_POINTER(scalloc(147,82););
printStats();
void* p326 = last_address;
PRINT_POINTER(srealloc(p311,119););
printStats();
void* p327 = last_address;
PRINT_POINTER(srealloc(p198,87););
printStats();
void* p328 = last_address;
PRINT_POINTER(srealloc(p312,156););
printStats();
void* p329 = last_address;
PRINT_POINTER(srealloc(p283,87););
printStats();
void* p330 = last_address;
PRINT_POINTER(srealloc(p125,18););
printStats();
void* p331 = last_address;
PRINT_POINTER(scalloc(105,151););
printStats();
void* p332 = last_address;
PRINT_POINTER(scalloc(240,124););
printStats();
void* p333 = last_address;
DEBUG_PRINT(sfree(p322););
printStats();
DEBUG_PRINT(sfree(p209););
printStats();
DEBUG_PRINT(sfree(p140););
printStats();
PRINT_POINTER(srealloc(p288,227););
printStats();
void* p334 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p335 = last_address;
DEBUG_PRINT(sfree(p152););
printStats();
DEBUG_PRINT(sfree(p333););
printStats();
PRINT_POINTER(smalloc(202););
printStats();
void* p336 = last_address;
PRINT_POINTER(smalloc(242););
printStats();
void* p337 = last_address;
PRINT_POINTER(srealloc(p337,213););
printStats();
void* p338 = last_address;
PRINT_POINTER(srealloc(p336,114););
printStats();
void* p339 = last_address;
PRINT_POINTER(srealloc(p264,73););
printStats();
void* p340 = last_address;
PRINT_POINTER(scalloc(105,45););
printStats();
void* p341 = last_address;
PRINT_POINTER(smalloc(156););
printStats();
void* p342 = last_address;
DEBUG_PRINT(sfree(p301););
printStats();
DEBUG_PRINT(sfree(p302););
printStats();
PRINT_POINTER(scalloc(84,77););
printStats();
void* p343 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p344 = last_address;
PRINT_POINTER(srealloc(p304,35););
printStats();
void* p345 = last_address;
PRINT_POINTER(srealloc(p284,64););
printStats();
void* p346 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p347 = last_address;
PRINT_POINTER(srealloc(p261,75););
printStats();
void* p348 = last_address;
PRINT_POINTER(scalloc(124,15););
printStats();
void* p349 = last_address;
PRINT_POINTER(scalloc(207,176););
printStats();
void* p350 = last_address;
PRINT_POINTER(scalloc(156,62););
printStats();
void* p351 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p352 = last_address;
DEBUG_PRINT(sfree(p243););
printStats();
PRINT_POINTER(smalloc(51););
printStats();
void* p353 = last_address;
}
