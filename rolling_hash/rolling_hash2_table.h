/**********************************************************************
  Copyright(c) 2011-2017 Intel Corporation All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********************************************************************/

#ifndef _ROLLING_HASH2_TABLE_H_
#define _ROLLING_HASH2_TABLE_H_

// values are fractional part of pi
// taken from:
//   http://www.herongyang.com/Cryptography/Blowfish-First-8366-Hex-Digits-of-PI.html
// taken from source code of BlowfishJ

uint64_t rolling_hash2_table1[256] = {
	0x243F6A8885A308D3,
	0x13198A2E03707344,
	0xA4093822299F31D0,
	0x082EFA98EC4E6C89,
	0x452821E638D01377,
	0xBE5466CF34E90C6C,
	0xC0AC29B7C97C50DD,
	0x3F84D5B5B5470917,
	0x9216D5D98979FB1B,
	0xD1310BA698DFB5AC,
	0x2FFD72DBD01ADFB7,
	0xB8E1AFED6A267E96,
	0xBA7C9045F12C7F99,
	0x24A19947B3916CF7,
	0x0801F2E2858EFC16,
	0x636920D871574E69,
	0xA458FEA3F4933D7E,
	0x0D95748F728EB658,
	0x718BCD5882154AEE,
	0x7B54A41DC25A59B5,
	0x9C30D5392AF26013,
	0xC5D1B023286085F0,
	0xCA417918B8DB38EF,
	0x8E79DCB0603A180E,
	0x6C9E0E8BB01E8A3E,
	0xD71577C1BD314B27,
	0x78AF2FDA55605C60,
	0xE65525F3AA55AB94,
	0x5748986263E81440,
	0x55CA396A2AAB10B6,
	0xB4CC5C341141E8CE,
	0xA15486AF7C72E993,
	0xB3EE1411636FBC2A,
	0x2BA9C55D741831F6,
	0xCE5C3E169B87931E,
	0xAFD6BA336C24CF5C,
	0x7A32538128958677,
	0x3B8F48986B4BB9AF,
	0xC4BFE81B66282193,
	0x61D809CCFB21A991,
	0x487CAC605DEC8032,
	0xEF845D5DE98575B1,
	0xDC262302EB651B88,
	0x23893E81D396ACC5,
	0x0F6D6FF383F44239,
	0x2E0B4482A4842004,
	0x69C8F04A9E1F9B5E,
	0x21C66842F6E96C9A,
	0x670C9C61ABD388F0,
	0x6A51A0D2D8542F68,
	0x960FA728AB5133A3,
	0x6EEF0B6C137A3BE4,
	0xBA3BF0507EFB2A98,
	0xA1F1651D39AF0176,
	0x66CA593E82430E88,
	0x8CEE8619456F9FB4,
	0x7D84A5C33B8B5EBE,
	0xE06F75D885C12073,
	0x401A449F56C16AA6,
	0x4ED3AA62363F7706,
	0x1BFEDF72429B023D,
	0x37D0D724D00A1248,
	0xDB0FEAD349F1C09B,
	0x075372C980991B7B,
	0x25D479D8F6E8DEF7,
	0xE3FE501AB6794C3B,
	0x976CE0BD04C006BA,
	0xC1A94FB6409F60C4,
	0x5E5C9EC2196A2463,
	0x68FB6FAF3E6C53B5,
	0x1339B2EB3B52EC6F,
	0x6DFC511F9B30952C,
	0xCC814544AF5EBD09,
	0xBEE3D004DE334AFD,
	0x660F2807192E4BB3,
	0xC0CBA85745C8740F,
	0xD20B5F39B9D3FBDB,
	0x5579C0BD1A60320A,
	0xD6A100C6402C7279,
	0x679F25FEFB1FA3CC,
	0x8EA5E9F8DB3222F8,
	0x3C7516DFFD616B15,
	0x2F501EC8AD0552AB,
	0x323DB5FAFD238760,
	0x53317B483E00DF82,
	0x9E5C57BBCA6F8CA0,
	0x1A87562EDF1769DB,
	0xD542A8F6287EFFC3,
	0xAC6732C68C4F5573,
	0x695B27B0BBCA58C8,
	0xE1FFA35DB8F011A0,
	0x10FA3D98FD2183B8,
	0x4AFCB56C2DD1D35B,
	0x9A53E479B6F84565,
	0xD28E49BC4BFB9790,
	0xE1DDF2DAA4CB7E33,
	0x62FB1341CEE4C6E8,
	0xEF20CADA36774C01,
	0xD07E9EFE2BF11FB4,
	0x95DBDA4DAE909198,
	0xEAAD8E716B93D5A0,
	0xD08ED1D0AFC725E0,
	0x8E3C5B2F8E7594B7,
	0x8FF6E2FBF2122B64,
	0x8888B812900DF01C,
	0x4FAD5EA0688FC31C,
	0xD1CFF191B3A8C1AD,
	0x2F2F2218BE0E1777,
	0xEA752DFE8B021FA1,
	0xE5A0CC0FB56F74E8,
	0x18ACF3D6CE89E299,
	0xB4A84FE0FD13E0B7,
	0x7CC43B81D2ADA8D9,
	0x165FA26680957705,
	0x93CC7314211A1477,
	0xE6AD206577B5FA86,
	0xC75442F5FB9D35CF,
	0xEBCDAF0C7B3E89A0,
	0xD6411BD3AE1E7E49,
	0x00250E2D2071B35E,
	0x226800BB57B8E0AF,
	0x2464369BF009B91E,
	0x5563911D59DFA6AA,
	0x78C14389D95A537F,
	0x207D5BA202E5B9C5,
	0x832603766295CFA9,
	0x11C819684E734A41,
	0xB3472DCA7B14A94A,
	0x1B5100529A532915,
	0xD60F573FBC9BC6E4,
	0x2B60A47681E67400,
	0x08BA6FB5571BE91F,
	0xF296EC6B2A0DD915,
	0xB6636521E7B9F9B6,
	0xFF34052EC5855664,
	0x53B02D5DA99F8FA1,
	0x08BA47996E85076A,
	0x4B7A70E9B5B32944,
	0xDB75092EC4192623,
	0xAD6EA6B049A7DF7D,
	0x9CEE60B88FEDB266,
	0xECAA8C71699A17FF,
	0x5664526CC2B19EE1,
	0x193602A575094C29,
	0xA0591340E4183A3E,
	0x3F54989A5B429D65,
	0x6B8FE4D699F73FD6,
	0xA1D29C07EFE830F5,
	0x4D2D38E6F0255DC1,
	0x4CDD20868470EB26,
	0x6382E9C6021ECC5E,
	0x09686B3F3EBAEFC9,
	0x3C9718146B6A70A1,
	0x687F358452A0E286,
	0xB79C5305AA500737,
	0x3E07841C7FDEAE5C,
	0x8E7D44EC5716F2B8,
	0xB03ADA37F0500C0D,
	0xF01C1F040200B3FF,
	0xAE0CF51A3CB574B2,
	0x25837A58DC0921BD,
	0xD19113F97CA92FF6,
	0x9432477322F54701,
	0x3AE5E58137C2DADC,
	0xC8B576349AF3DDA7,
	0xA94461460FD0030E,
	0xECC8C73EA4751E41,
	0xE238CD993BEA0E2F,
	0x3280BBA1183EB331,
	0x4E548B384F6DB908,
	0x6F420D03F60A04BF,
	0x2CB8129024977C79,
	0x5679B072BCAF89AF,
	0xDE9A771FD9930810,
	0xB38BAE12DCCF3F2E,
	0x5512721F2E6B7124,
	0x501ADDE69F84CD87,
	0x7A5847187408DA17,
	0xBC9F9ABCE94B7D8C,
	0xEC7AEC3ADB851DFA,
	0x63094366C464C3D2,
	0xEF1C18473215D908,
	0xDD433B3724C2BA16,
	0x12A14D432A65C451,
	0x50940002133AE4DD,
	0x71DFF89E10314E55,
	0x81AC77D65F11199B,
	0x043556F1D7A3C76B,
	0x3C11183B5924A509,
	0xF28FE6ED97F1FBFA,
	0x9EBABF2C1E153C6E,
	0x86E34570EAE96FB1,
	0x860E5E0A5A3E2AB3,
	0x771FE71C4E3D06FA,
	0x2965DCB999E71D0F,
	0x803E89D65266C825,
	0x2E4CC9789C10B36A,
	0xC6150EBA94E2EA78,
	0xA5FC3C531E0A2DF4,
	0xF2F74EA7361D2B3D,
	0x1939260F19C27960,
	0x5223A708F71312B6,
	0xEBADFE6EEAC31F66,
	0xE3BC4595A67BC883,
	0xB17F37D1018CFF28,
	0xC332DDEFBE6C5AA5,
	0x6558218568AB9802,
	0xEECEA50FDB2F953B,
	0x2AEF7DAD5B6E2F84,
	0x1521B62829076170,
	0xECDD4775619F1510,
	0x13CCA830EB61BD96,
	0x0334FE1EAA0363CF,
	0xB5735C904C70A239,
	0xD59E9E0BCBAADE14,
	0xEECC86BC60622CA7,
	0x9CAB5CABB2F3846E,
	0x648B1EAF19BDF0CA,
	0xA02369B9655ABB50,
	0x40685A323C2AB4B3,
	0x319EE9D5C021B8F7,
	0x9B540B19875FA099,
	0x95F7997E623D7DA8,
	0xF837889A97E32D77,
	0x11ED935F16681281,
	0x0E358829C7E61FD6,
	0x96DEDFA17858BA99,
	0x57F584A51B227263,
	0x9B83C3FF1AC24696,
	0xCDB30AEB532E3054,
	0x8FD948E46DBC3128,
	0x58EBF2EF34C6FFEA,
	0xFE28ED61EE7C3C73,
	0x5D4A14D9E864B7E3,
	0x42105D14203E13E0,
	0x45EEE2B6A3AAABEA,
	0xDB6C4F15FACB4FD0,
	0xC742F442EF6ABBB5,
	0x654F3B1D41CD2105,
	0xD81E799E86854DC7,
	0xE44B476A3D816250,
	0xCF62A1F25B8D2646,
	0xFC8883A0C1C7B6A3,
	0x7F1524C369CB7492,
	0x47848A0B5692B285,
	0x095BBF00AD19489D,
	0x1462B17423820E00,
	0x58428D2A0C55F5EA,
	0x1DADF43E233F7061,
	0x3372F0928D937E41,
	0xD65FECF16C223BDB,
	0x7CDE3759CBEE7460,
	0x4085F2A7CE77326E,
	0xA607808419F8509E,
	0xE8EFD85561D99735,
	0xA969A7AAC50C06C2,
};
#endif // _ROLLING_HASH2_TABLE_H_
