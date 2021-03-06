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
                        PRINT_POINTER(scalloc(188,180););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(scalloc(168,194););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(54,178););
printStats();
void* p2 = last_address;
PRINT_POINTER(srealloc(p2,96););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p4 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p1,36););
printStats();
void* p5 = last_address;
PRINT_POINTER(srealloc(p5,223););
printStats();
void* p6 = last_address;
PRINT_POINTER(smalloc(208););
printStats();
void* p7 = last_address;
PRINT_POINTER(srealloc(p6,25););
printStats();
void* p8 = last_address;
PRINT_POINTER(smalloc(84););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(155););
printStats();
void* p10 = last_address;
PRINT_POINTER(scalloc(77,19););
printStats();
void* p11 = last_address;
PRINT_POINTER(srealloc(p8,174););
printStats();
void* p12 = last_address;
PRINT_POINTER(smalloc(178););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(46,35););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p14););
printStats();
PRINT_POINTER(smalloc(73););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(65,225););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p16,18););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(207););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p17,228););
printStats();
void* p19 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p20 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p21 = last_address;
PRINT_POINTER(srealloc(p3,120););
printStats();
void* p22 = last_address;
PRINT_POINTER(smalloc(242););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p12,1););
printStats();
void* p24 = last_address;
PRINT_POINTER(srealloc(p13,209););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p19,20););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(203););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(4,209););
printStats();
void* p28 = last_address;
PRINT_POINTER(smalloc(95););
printStats();
void* p29 = last_address;
PRINT_POINTER(scalloc(19,86););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(226););
printStats();
void* p31 = last_address;
PRINT_POINTER(srealloc(p29,229););
printStats();
void* p32 = last_address;
PRINT_POINTER(smalloc(130););
printStats();
void* p33 = last_address;
PRINT_POINTER(srealloc(p33,66););
printStats();
void* p34 = last_address;
PRINT_POINTER(scalloc(222,134););
printStats();
void* p35 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p25,237););
printStats();
void* p37 = last_address;
PRINT_POINTER(smalloc(42););
printStats();
void* p38 = last_address;
PRINT_POINTER(smalloc(139););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p34,111););
printStats();
void* p40 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(smalloc(209););
printStats();
void* p41 = last_address;
PRINT_POINTER(smalloc(124););
printStats();
void* p42 = last_address;
PRINT_POINTER(smalloc(244););
printStats();
void* p43 = last_address;
PRINT_POINTER(smalloc(209););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(218););
printStats();
void* p45 = last_address;
PRINT_POINTER(srealloc(p10,146););
printStats();
void* p46 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(srealloc(p20,194););
printStats();
void* p47 = last_address;
PRINT_POINTER(scalloc(69,26););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p18,160););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(82,227););
printStats();
void* p50 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(236););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(238,133););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(197,235););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p26););
printStats();
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(scalloc(107,206););
printStats();
void* p55 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(79,232););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(140););
printStats();
void* p58 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(srealloc(p42,162););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p39,15););
printStats();
void* p60 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
DEBUG_PRINT(sfree(p27););
printStats();
DEBUG_PRINT(sfree(p58););
printStats();
PRINT_POINTER(smalloc(34););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(126););
printStats();
void* p62 = last_address;
PRINT_POINTER(scalloc(147,101););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p43,219););
printStats();
void* p64 = last_address;
PRINT_POINTER(srealloc(p22,79););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p51,207););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p38,163););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p67,65););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(13,173););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p70 = last_address;
PRINT_POINTER(srealloc(p49,210););
printStats();
void* p71 = last_address;
PRINT_POINTER(scalloc(54,134););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(srealloc(p50,202););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p48,38););
printStats();
void* p74 = last_address;
PRINT_POINTER(scalloc(191,202););
printStats();
void* p75 = last_address;
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(scalloc(192,121););
printStats();
void* p76 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(srealloc(p56,70););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
DEBUG_PRINT(sfree(p77););
printStats();
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(smalloc(174););
printStats();
void* p78 = last_address;
PRINT_POINTER(smalloc(136););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(127,138););
printStats();
void* p80 = last_address;
PRINT_POINTER(scalloc(175,213););
printStats();
void* p81 = last_address;
PRINT_POINTER(scalloc(194,190););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(113););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p61,114););
printStats();
void* p84 = last_address;
PRINT_POINTER(scalloc(33,177););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(srealloc(p53,202););
printStats();
void* p86 = last_address;
PRINT_POINTER(srealloc(p45,237););
printStats();
void* p87 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p88 = last_address;
PRINT_POINTER(scalloc(0,44););
printStats();
void* p89 = last_address;
PRINT_POINTER(scalloc(114,79););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p91 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p92 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(srealloc(p73,174););
printStats();
void* p93 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(scalloc(103,174););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p79,65););
printStats();
void* p95 = last_address;
PRINT_POINTER(scalloc(138,45););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p88,75););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(153,1););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p92,249););
printStats();
void* p99 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p100 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p82,248););
printStats();
void* p103 = last_address;
PRINT_POINTER(srealloc(p100,105););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(141,188););
printStats();
void* p105 = last_address;
PRINT_POINTER(scalloc(187,81););
printStats();
void* p106 = last_address;
PRINT_POINTER(srealloc(p35,246););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
DEBUG_PRINT(sfree(p75););
printStats();
PRINT_POINTER(srealloc(p80,112););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p87,229););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(114,207););
printStats();
void* p110 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p111 = last_address;
PRINT_POINTER(scalloc(159,136););
printStats();
void* p112 = last_address;
DEBUG_PRINT(sfree(p86););
printStats();
DEBUG_PRINT(sfree(p90););
printStats();
PRINT_POINTER(srealloc(p97,94););
printStats();
void* p113 = last_address;
DEBUG_PRINT(sfree(p109););
printStats();
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(smalloc(113););
printStats();
void* p114 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p115 = last_address;
PRINT_POINTER(smalloc(120););
printStats();
void* p116 = last_address;
PRINT_POINTER(smalloc(63););
printStats();
void* p117 = last_address;
PRINT_POINTER(srealloc(p78,64););
printStats();
void* p118 = last_address;
PRINT_POINTER(scalloc(242,96););
printStats();
void* p119 = last_address;
PRINT_POINTER(srealloc(p98,241););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p81,174););
printStats();
void* p121 = last_address;
PRINT_POINTER(smalloc(28););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(srealloc(p41,50););
printStats();
void* p123 = last_address;
PRINT_POINTER(srealloc(p46,15););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
PRINT_POINTER(srealloc(p31,105););
printStats();
void* p125 = last_address;
PRINT_POINTER(scalloc(69,189););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(smalloc(29););
printStats();
void* p127 = last_address;
PRINT_POINTER(srealloc(p71,227););
printStats();
void* p128 = last_address;
PRINT_POINTER(smalloc(194););
printStats();
void* p129 = last_address;
PRINT_POINTER(smalloc(103););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(119,40););
printStats();
void* p131 = last_address;
PRINT_POINTER(scalloc(18,168););
printStats();
void* p132 = last_address;
PRINT_POINTER(scalloc(28,227););
printStats();
void* p133 = last_address;
PRINT_POINTER(scalloc(181,35););
printStats();
void* p134 = last_address;
PRINT_POINTER(srealloc(p113,168););
printStats();
void* p135 = last_address;
PRINT_POINTER(srealloc(p131,241););
printStats();
void* p136 = last_address;
PRINT_POINTER(scalloc(81,51););
printStats();
void* p137 = last_address;
DEBUG_PRINT(sfree(p124););
printStats();
DEBUG_PRINT(sfree(p136););
printStats();
PRINT_POINTER(smalloc(165););
printStats();
void* p138 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p140 = last_address;
PRINT_POINTER(srealloc(p30,161););
printStats();
void* p141 = last_address;
PRINT_POINTER(srealloc(p60,107););
printStats();
void* p142 = last_address;
PRINT_POINTER(srealloc(p96,197););
printStats();
void* p143 = last_address;
DEBUG_PRINT(sfree(p121););
printStats();
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(smalloc(241););
printStats();
void* p144 = last_address;
PRINT_POINTER(scalloc(130,233););
printStats();
void* p145 = last_address;
PRINT_POINTER(srealloc(p145,52););
printStats();
void* p146 = last_address;
PRINT_POINTER(srealloc(p130,51););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(174,69););
printStats();
void* p148 = last_address;
PRINT_POINTER(srealloc(p147,3););
printStats();
void* p149 = last_address;
PRINT_POINTER(scalloc(203,178););
printStats();
void* p150 = last_address;
PRINT_POINTER(scalloc(247,28););
printStats();
void* p151 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(srealloc(p84,90););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p116,98););
printStats();
void* p153 = last_address;
PRINT_POINTER(srealloc(p144,101););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p7););
printStats();
PRINT_POINTER(srealloc(p68,35););
printStats();
void* p155 = last_address;
PRINT_POINTER(srealloc(p85,205););
printStats();
void* p156 = last_address;
PRINT_POINTER(smalloc(67););
printStats();
void* p157 = last_address;
PRINT_POINTER(scalloc(14,102););
printStats();
void* p158 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p159 = last_address;
PRINT_POINTER(scalloc(194,165););
printStats();
void* p160 = last_address;
DEBUG_PRINT(sfree(p93););
printStats();
PRINT_POINTER(smalloc(24););
printStats();
void* p161 = last_address;
DEBUG_PRINT(sfree(p129););
printStats();
PRINT_POINTER(scalloc(91,91););
printStats();
void* p162 = last_address;
PRINT_POINTER(srealloc(p134,3););
printStats();
void* p163 = last_address;
PRINT_POINTER(scalloc(160,155););
printStats();
void* p164 = last_address;
PRINT_POINTER(scalloc(120,131););
printStats();
void* p165 = last_address;
PRINT_POINTER(scalloc(218,31););
printStats();
void* p166 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p167 = last_address;
PRINT_POINTER(scalloc(187,210););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(246,39););
printStats();
void* p169 = last_address;
PRINT_POINTER(smalloc(83););
printStats();
void* p170 = last_address;
PRINT_POINTER(smalloc(177););
printStats();
void* p171 = last_address;
PRINT_POINTER(srealloc(p153,169););
printStats();
void* p172 = last_address;
PRINT_POINTER(scalloc(174,37););
printStats();
void* p173 = last_address;
PRINT_POINTER(smalloc(165););
printStats();
void* p174 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(srealloc(p104,56););
printStats();
void* p175 = last_address;
DEBUG_PRINT(sfree(p161););
printStats();
PRINT_POINTER(scalloc(29,166););
printStats();
void* p176 = last_address;
PRINT_POINTER(srealloc(p52,225););
printStats();
void* p177 = last_address;
PRINT_POINTER(srealloc(p157,171););
printStats();
void* p178 = last_address;
PRINT_POINTER(srealloc(p120,2););
printStats();
void* p179 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(67););
printStats();
void* p181 = last_address;
PRINT_POINTER(scalloc(85,76););
printStats();
void* p182 = last_address;
PRINT_POINTER(srealloc(p176,235););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(196););
printStats();
void* p184 = last_address;
PRINT_POINTER(scalloc(66,52););
printStats();
void* p185 = last_address;
PRINT_POINTER(scalloc(196,234););
printStats();
void* p186 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p187 = last_address;
DEBUG_PRINT(sfree(p162););
printStats();
PRINT_POINTER(srealloc(p62,106););
printStats();
void* p188 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
DEBUG_PRINT(sfree(p107););
printStats();
PRINT_POINTER(smalloc(247););
printStats();
void* p189 = last_address;
PRINT_POINTER(srealloc(p128,35););
printStats();
void* p190 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p66,68););
printStats();
void* p192 = last_address;
DEBUG_PRINT(sfree(p186););
printStats();
PRINT_POINTER(scalloc(222,123););
printStats();
void* p193 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p194 = last_address;
PRINT_POINTER(smalloc(188););
printStats();
void* p195 = last_address;
PRINT_POINTER(srealloc(p111,232););
printStats();
void* p196 = last_address;
DEBUG_PRINT(sfree(p151););
printStats();
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(scalloc(234,43););
printStats();
void* p197 = last_address;
DEBUG_PRINT(sfree(p150););
printStats();
PRINT_POINTER(smalloc(124););
printStats();
void* p198 = last_address;
PRINT_POINTER(scalloc(221,238););
printStats();
void* p199 = last_address;
PRINT_POINTER(scalloc(109,58););
printStats();
void* p200 = last_address;
PRINT_POINTER(scalloc(8,197););
printStats();
void* p201 = last_address;
PRINT_POINTER(srealloc(p173,77););
printStats();
void* p202 = last_address;
PRINT_POINTER(srealloc(p175,196););
printStats();
void* p203 = last_address;
PRINT_POINTER(smalloc(231););
printStats();
void* p204 = last_address;
PRINT_POINTER(srealloc(p180,118););
printStats();
void* p205 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p206 = last_address;
PRINT_POINTER(smalloc(59););
printStats();
void* p207 = last_address;
PRINT_POINTER(smalloc(132););
printStats();
void* p208 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p209 = last_address;
PRINT_POINTER(smalloc(97););
printStats();
void* p210 = last_address;
PRINT_POINTER(smalloc(200););
printStats();
void* p211 = last_address;
DEBUG_PRINT(sfree(p154););
printStats();
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(srealloc(p187,110););
printStats();
void* p212 = last_address;
DEBUG_PRINT(sfree(p164););
printStats();
PRINT_POINTER(srealloc(p148,51););
printStats();
void* p213 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p214 = last_address;
PRINT_POINTER(smalloc(97););
printStats();
void* p215 = last_address;
PRINT_POINTER(srealloc(p205,61););
printStats();
void* p216 = last_address;
PRINT_POINTER(scalloc(192,159););
printStats();
void* p217 = last_address;
PRINT_POINTER(scalloc(108,198););
printStats();
void* p218 = last_address;
PRINT_POINTER(srealloc(p138,227););
printStats();
void* p219 = last_address;
PRINT_POINTER(smalloc(166););
printStats();
void* p220 = last_address;
DEBUG_PRINT(sfree(p158););
printStats();
PRINT_POINTER(srealloc(p208,133););
printStats();
void* p221 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p222 = last_address;
DEBUG_PRINT(sfree(p172););
printStats();
PRINT_POINTER(smalloc(25););
printStats();
void* p223 = last_address;
DEBUG_PRINT(sfree(p222););
printStats();
PRINT_POINTER(scalloc(154,222););
printStats();
void* p224 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p225 = last_address;
PRINT_POINTER(scalloc(170,243););
printStats();
void* p226 = last_address;
PRINT_POINTER(scalloc(35,229););
printStats();
void* p227 = last_address;
PRINT_POINTER(smalloc(34););
printStats();
void* p228 = last_address;
PRINT_POINTER(smalloc(95););
printStats();
void* p229 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p230 = last_address;
PRINT_POINTER(scalloc(133,183););
printStats();
void* p231 = last_address;
DEBUG_PRINT(sfree(p217););
printStats();
DEBUG_PRINT(sfree(p199););
printStats();
PRINT_POINTER(smalloc(160););
printStats();
void* p232 = last_address;
PRINT_POINTER(smalloc(133););
printStats();
void* p233 = last_address;
DEBUG_PRINT(sfree(p156););
printStats();
PRINT_POINTER(smalloc(49););
printStats();
void* p234 = last_address;
DEBUG_PRINT(sfree(p197););
printStats();
DEBUG_PRINT(sfree(p215););
printStats();
DEBUG_PRINT(sfree(p185););
printStats();
PRINT_POINTER(scalloc(148,120););
printStats();
void* p235 = last_address;
PRINT_POINTER(srealloc(p168,64););
printStats();
void* p236 = last_address;
PRINT_POINTER(srealloc(p220,98););
printStats();
void* p237 = last_address;
PRINT_POINTER(smalloc(118););
printStats();
void* p238 = last_address;
PRINT_POINTER(srealloc(p203,202););
printStats();
void* p239 = last_address;
PRINT_POINTER(srealloc(p94,39););
printStats();
void* p240 = last_address;
PRINT_POINTER(srealloc(p198,47););
printStats();
void* p241 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(scalloc(36,34););
printStats();
void* p242 = last_address;
DEBUG_PRINT(sfree(p108););
printStats();
PRINT_POINTER(srealloc(p95,120););
printStats();
void* p243 = last_address;
PRINT_POINTER(smalloc(141););
printStats();
void* p244 = last_address;
PRINT_POINTER(scalloc(65,11););
printStats();
void* p245 = last_address;
DEBUG_PRINT(sfree(p140););
printStats();
PRINT_POINTER(smalloc(105););
printStats();
void* p246 = last_address;
PRINT_POINTER(srealloc(p114,99););
printStats();
void* p247 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p248 = last_address;
PRINT_POINTER(smalloc(63););
printStats();
void* p249 = last_address;
PRINT_POINTER(srealloc(p137,156););
printStats();
void* p250 = last_address;
DEBUG_PRINT(sfree(p192););
printStats();
PRINT_POINTER(scalloc(46,178););
printStats();
void* p251 = last_address;
PRINT_POINTER(srealloc(p102,77););
printStats();
void* p252 = last_address;
PRINT_POINTER(scalloc(138,110););
printStats();
void* p253 = last_address;
PRINT_POINTER(smalloc(217););
printStats();
void* p254 = last_address;
DEBUG_PRINT(sfree(p246););
printStats();
PRINT_POINTER(smalloc(226););
printStats();
void* p255 = last_address;
PRINT_POINTER(scalloc(106,191););
printStats();
void* p256 = last_address;
PRINT_POINTER(srealloc(p238,6););
printStats();
void* p257 = last_address;
PRINT_POINTER(smalloc(224););
printStats();
void* p258 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p259 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p260 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p261 = last_address;
PRINT_POINTER(scalloc(224,23););
printStats();
void* p262 = last_address;
PRINT_POINTER(smalloc(245););
printStats();
void* p263 = last_address;
DEBUG_PRINT(sfree(p182););
printStats();
PRINT_POINTER(srealloc(p221,243););
printStats();
void* p264 = last_address;
PRINT_POINTER(srealloc(p256,144););
printStats();
void* p265 = last_address;
DEBUG_PRINT(sfree(p214););
printStats();
PRINT_POINTER(smalloc(159););
printStats();
void* p266 = last_address;
PRINT_POINTER(scalloc(213,38););
printStats();
void* p267 = last_address;
DEBUG_PRINT(sfree(p159););
printStats();
PRINT_POINTER(scalloc(249,17););
printStats();
void* p268 = last_address;
PRINT_POINTER(scalloc(36,72););
printStats();
void* p269 = last_address;
PRINT_POINTER(srealloc(p122,7););
printStats();
void* p270 = last_address;
DEBUG_PRINT(sfree(p163););
printStats();
PRINT_POINTER(srealloc(p125,60););
printStats();
void* p271 = last_address;
}
