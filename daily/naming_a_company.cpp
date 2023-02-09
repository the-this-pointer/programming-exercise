// https://leetcode.com/problems/naming-a-company/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    unordered_map<int, unordered_map<string, int>> hash;
    long long ret = 0;
    for (int i = 0; i < ideas.size(); ++i) {
      hash[ideas[i][0] - 'a'][ideas[i].substr(1)]++;
    }

    for (int i = 0; i < 25; ++i) {
      for (int j = i+1; j < 26; ++j) {
        long long count = 0;

        for(auto &it : hash[i])
          if(hash[j].find(it.first) != hash[j].end()) count++;

        ret += 2ll * (hash[i].size() - count) * (hash[j].size() - count);
      }
    }

    return ret;
	}
};

int main()
{
	vector<string> ideas = { "coffee","donuts","time","toffee" };
	//vector<string> ideas = { "umbjkqzxq","pukpvll","vkg","p","rcjiwvnval","nkw","lmttcqodww","girombo","q","k","xbncaiy","ds","shyj","dkvlxd","bh","qgxlwkpuzg","dvbmk","neujarrge","bfjg","gfs","ppffyoph","qhmz","vu","heqwzlkc","yvkjiuhcyh","oushmmw","qenbbupga","gc","gsrjks","wnweolpkfc","steykbhav","odwwmy","qslz","rwve","ewcuiazy","jimamcajb","mh","calskn","djvalt","h","xgbaub","qvbmk","zmmsmzzbd","yoiqlkhv","i","e","rnuvs","lsqespk","nlrbnrmzb","tdwec","clft","bxdkwuoq","rqmtka","fnn","rkaimnoisl","bab","fna","ouhavlfzrz","jt","yzylnnr","dpgk","qsed","hnqc","fanpqiret","lcslhgk","y","mdvvm","qfjg","xdblpnc","zfefgw","vd","qnn","dcktkxes","z","bjcagsrgui","vifma","tacssz","fonjprjpk","wnluwotgag","lecrpz","x","uirxxolu","jxhxuutmh","tupze","nhvnz","bsw","lwlyxtjie","je","bvkjiuhcyh","zviguxsfp","qi","mhh","cwctfi","orxibn","ldtimkf","kxbeoqre","ssukg","emwr","td","yjfcqgyapb","obmqwdinkw","bzpo","kifvvix","blgqjrlrk","hkma","nva","mjked","pmvefxaqgp","tctjt","tsmkuo","rgnx","oginhbxr","jpd","yhijas","mqrrkwsx","d","dzb","lswlqicj","whlfqpayyc","nslckx","hepmc","mlxvkp","ioysrcpscd","bfyyepvprd","wqqqr","smvefxaqgp","trksjqskov","iofpmla","v","kkigirf","pniaprgsci","pvpuh","ua","vauxsyq","eexutaueh","wyrge","fytajd","ljo","wqnwgn","wcabrwd","hzvpxyw","as","uvbjd","sfpbcglj","vuj","hdx","maivvutumo","eygbztdqob","sb","abxtkp","m","obbzukmu","jaskogmrug","mlkz","s","wi","naxwzzfg","anan","fc","gil","wkaimnoisl","xrtegsk","xov","mqqeyqonsl","cil","xno","r","ps","bohvlnydaa","uhh","op","phm","ikbhmdu","spsvneuyuw","zbbzukmu","n","xzisntc","bgbalpvmb","bustdwy","gbuu","vkk","spbueyu","uilx","vyyv","wrbvwfsu","rxcu","mfkglqre","hisgvnldz","hnohzrollt","ndmnddtill","ufaexhv","ny","dkq","jyyqyszww","tt","sfk","tplskphj","ijvjsf","zwwrm","zkuzfcsffo","wcumg","imahe","dpci","ibclarufj","ypfsmrvciy","wgo","j","ubzvoku","rxrpcxp","abkgbl","mks","yn","apymasgqu","xvgz","aw","pnszlyx","t","fbg","rowsgg","wqho","lqfs","slxsrodm","ik","bo","ojudb","mom","goqpjm","sgirpfph","jl","meujarrge","gklkcpovuc","plxmzdh","jqhdlbs","okasbq","pvvj","pvwuckghtt","esgv","c","nfgrzldt","rggivhg","utn","bspvbpqtq","uldt","nzgeoekikh","zauyw","koh","aoabs","nvweuwl","aegkcyq","b","lppmtygo","ct","yyhlrdq","lybqh","fp","jctfsser","iubw","btkeqlhac","eiw","yilx","ujlugifygx","mrcbipvklo","ea","ccqalexmgf","trbhcxvsh","os","mfompy","jdujswknl","dvm","vlqq","oeduc","uvhvmcqh","zof","deotapc","nrbhcxvsh","dizmf","vzi","qoyejb","sawuyrjb","dyeguvxrws","jozfoe","yarqibtb","uvl","kiihmh","wwatrox","bs","cv","wseapvr","tnluwotgag","lb","kpwwukubf","mggokr","iseapvr","gglvsx","hzmgy","qcz","gqzenum","ebxqf","uaivvutumo","nj","kg","tdnrkc","wwctfi","tjxfgu","yrjxrtol","jwwjhd","hzghcrzsi","fzof","qisstsks","qscghb","bvylufabv","yfal","la","oea","tvf","tov","uzronf","txl","zxnfub","vexsgyfxvf","nyvtqhkv","nn","jodoj","bg","hfxheh","ndt","ivylufabv","ujn","zszki","ronzqhrk","tilx","jiht","nkahsu","kmbrdl","oozupwnjjm","aqtcg","azmgy","lcaz","nhrwreqhvt","qkr","onxpimofg","yd","bvjq","wlkmze","gjohygbd","oqx","zhur","aaxjtgw","kuda","fyqx","na","pom","rejxy","su","twcqq","sxm","kzfas","rhcehcecl","sos","tgtvi","mbdv","nk","rgiqxdo","uwm","zt","altudeqf","oxu","rvbpmsg","ujh","pzvpxyw","fkbhmdu","hydconh","eeofrc","aajklls","krjssea","jtf","mj","dwm","fg","cuw","tzwaaeptvv","cggjhv","wsrh","qvmrmc","fmwhbnbcfp","dtxbykvxh","un","aaooyaiis","xwshx","wjk","jjohygbd","qysmszz","oxtor","glcm","hntpypaf","ombq","epio","jshbkoih","dzm","gos","idnbfnzn","lu","cx","qlrgfvlc","woproiwv","wj","zits","yqumolspy","gwjawmvig","diigsgtjms","eckuarjpju","gpcl","sl","jendzhopt","yvecgfll","dvzgreuo","hir","pjoas","rc","npcggy","jufh","g","jzylnnr","wzbtnjbknr","qzylnnr","vxv","oavmsxf","xwzsfebwmd","fponb","nuvfnzvsx","mohbeiy","gcyawvp","sfbvhpytkm","gvlxbuyx","xwxuv","cmyhblsie","wlc","eh","l","yeqhi","ovyvts","ckufilu","py","fkbamckps","byxepxvyjj","hyzlcyogs","khvpgjt","xacat","vkqvhv","bube","tyvtqhkv","u","rncndomho","mhgqthnhif","qeggb","cqrs","yag","mviguxsfp","jcbjqwn","xcehntauk","gfll","hujr","itwcweqtqx","w","kubs","vmrgnmenm","qoiqj","eztzj","whngxa","nvbmk","mmabvvav","mdl","zknmj","uwgzmquy","dqtcg","ixsgkrygx","ppwph","hqleqjyq","efbx","ihq","odnbfnzn","cmeqdcl","twkx","nlpkgmnx","lw","nu","zrbymxrkl","cq","doecco","ec","ocirbvpe","scjej","uzsabqgu","kwh","nydeomfqoh","he","jwxlytdl","zjkotvfj","omdgr","ijtd","ksm","gndqapnf","pteqvvlg","hoym","woh","am","msykm","slrbnrmzb","izxzzgyvn","cyzlcyogs","ep","voeqjqml","vyilhon","f","ssy","oohpz","pmr","jrh","vibuerlx","lmr","hyxicrtr","vimh","kc","pbm","weymslgox","fq","bniroaeiha","dvlxbuyx","ejjn","dup","xibmwgkz","ovoxt","tvihndo","rdjyclox","zy","ont","vbxzfhn","vj","vlj","vnlu","orttuytppy","qphckxhhwz","gbjq","evmvnvhhb","bjil","szxhuelmbv","wzd","rvabkhz","bbcytmpy","ovacbic","fjht","vfbpbu","rvacbic","cqfgwqmwe","teqhi","ttifrsm","qlybdkp","wzfvyvvao","lslz","iqfgwqmwe","ofjvapevok","tcirbvpe","kifvw","uleba","jgxxgfbsa","xjwgq","qzzu","mtsjftbtd","bibarcosd","o","nrvkumzov","fh","oartwd","jgwgkph","bwh","cp","kvrpqr","mi","ivcxzkil","eqcokrui","qbxmmrotf","fqpnxdxq","gmdcxrznt","cyeignmz","reujg","qhm","msrxuljljq","musmodn","ibvnlsper","kmblpieez","bdtimkf","vqhv","pzf","kkbamckps","optbagb","bpcl","ypaidu","xwctfi","jnp","xvel","unjx","yjjn","buw","chrqhhgak","wbcytmpy","nggjhv","reotxd","hmgiuvygys","dh","mv","nfcvyigcm","exwmvsaf","mlqfrhnqvz","glrbnrmzb","yyxepxvyjj","pydja","pbclarufj","shbbs","prq","nzlm","wvdic","rfcaw","clfjb","vawwcd","kgjna","zrzrzlq","nuh","mqvihufmgr","at","hbjaefvm","xtue","mgeggovk","imbjkqzxq","uoegvdzt","qvs","azumljnq","gsvkkcurj","kyapnmkg","cdblpnc","jrtegsk","li","cyumbe","jyzlcyogs","reotp","ykggwbbjw","mclkucy","mvcurs","hk","oaqoi","umbrdl","nipa","axoa","fy","jmtlxdnugk","ibnr","ialkzms","swqzixuue","sagbysucx","bsqlf","iyjdx","hzw","zs","qxfes","avhsrebd","dbyoghzqba","fhvl","ifjg","gqxctnmtsc","qqtmerhqvu","iwve","ayvq","jmqfhwhoma","unw","zdwec","fpeajcj","xipgs","gkfgupsx","it","shijas","uzrqt","cobdpkev","rqie","zpfgtrlwxq","kgrxttbnk","bhm","ekzeahlaj","cwldujo","hvpwfa","ipg","junuiu","xkc","kocapk","epans","xsi","uctjt","vcmcz","eeh","unqv","qelpxv","fkkgckwia","kej","jgqankyo","ozovox","kaxvyveljz","jydbbp","mcfqttattp","oocrkjjg","tim","tqcokrui","hayqt","anrlv","lvmtybl","vqt","yz","md","ordoybkrt","hmgfbyibf","goegvdzt","lhfhsmfnmn","ostboldc","ywnjpxcu","fzahq","axdkwuoq","gn","vo","bjvzfvtwm","rhmyuyhv","tiuhxddtg","qk","txpjhdt","zbjq","ga","ba","zrnwwm","mme","fzxzzgyvn","pshtkz","rndqapnf","jfhrygui","jhdzo","ngeggovk","cjlugifygx","bu","pulsgxi","xhvxo","faghmhppg","gylnexv","urjssea","qkpgrprgp","fsekgzow","agnx","tk","llwgby","shkbb","wpmsm","ofxfmdpxf","pkvv","tstf","wllkssoijx","chur","porcn","zckyldjf","uhcfa","pcfqttattp","gqg","ddckmei","yja","mvuw","cxoa","cyk","bqsuy","ohpujlfe","hsowsf","ykogg","askzchc","igtru","rihp","omrdjpb","cr","jqmephihy","iwqzixuue","ewugxn","paaelpqiee","rxdkwuoq","spwofmr","uxuolyc","ampzst","ke","del","qjkotvfj","ok","earodd","xfgap","dsapnlewn","ulafnljgni","kmr","jkcod","wtx","mfwxkxy","hpuzfxrgzy","awve","xzo","nvrjieimw","ofmthso","barqibtb","nd","bhiuyronul","don","zhucdnk","nyjdx","vtebi","dfskurv","ymwqtjknou","sggeeadvn","kqq","bvfgaurvo","izizuzqy","epkvskmru","esjk","dsqjqn","cdrf","lepmc","wyqg","awzsfebwmd","acwxqhajk","jnn","rrkj","wfyhmsiqn","hcbdjizgsk","tdaxio","wndqapnf","ebdhijfpv","cxnzc","jkygu","iube","eqpkvaqlaa","zgvajyer","zbbzf","bdc","txxpab","nuxkg","ziaxgkse","jz","ucx","ywyo","xryk","etxa","yjo","epuxzwe","qxl","yhlfqpayyc","ogxlwkpuzg","lvel","udmzpscq","vqcmn","xnc","jsbltffv","dsu","eigvztvab","qxlalge","dt","njdqeft","oal","kgoudtvln","aqus","xrwa","fcl","yk","lubw","dfvr","bomreyonoy","xdsjg","kvmpihucp","vgiwefn","zsohzpvzd","lno","fygl","lmgzzoj","ykcbwqlh","jmcrzyswyl","frjssea","ippmtygo","rnn","svzdxurtz","gwhwfrq","rfpraqu","iilx","wt","vteqvvlg","qspw","wakgylaqfv","avuifrmq","rdsjg","ctoz","jlmdxxny","ch","txiee","avbmk","cpci","cuacifxt","hin","cpjy","rgafkdrgz","mgxsrgoj","xzekuxus","likcubqr","autuwsa","ebbeviftb","bm","dendzhopt","cmqfhwhoma","flmyf","nzsbfkbgb","ccmm","kp","xxbycsyvls","vulylq","dmldvs","ywbfbmuvbf","fuxmdwzd","lhmtjoxj","kvmregsd","wyjev","xodr","tpans","cesxtenzc","lkps","wbnoxpx","lwir","giiqvca","oxz","wmwqtjknou","rdzvnektnc","mhy","pqxqa","qq","simcgg","avepppsj","fjeellh","vglvsx","in","dj","biffzgm","rkqd","qrrcari","ldazbzwdr","mxpyclf","obbeviftb","runypktart","zkjjcq","vqtmerhqvu","pdqjxcse","reduc","digvztvab","cxiio","vqtcg","geo","zkk","vomfjmfay","gdsjg","ys","crh","kpcl","bfayagnnlm","zxdkwuoq","xxghxzcna","lcvjqhi","zu","ydaed","pntpypaf","comximaqjg","hwyo","uascg","nonzuouep","ljvyhoev","cll","pjprtbqcau","sjzutso","tv","imcrzyswyl","kemvplwc","phmz","fitvf","sjuzik","culcbvo","tma","fawuyrjb","zyilhon","grrm","luwmkginr","axoajptvwk","diswrvhxh","ozatodhkaz","xkfrgpsvk","mrbirdnzb","bdcpcnlm","soepwr","qpmtgqyqr","xmj","igw","pwnjpxcu","lik","gtstf","xjhhrp","vsqnnqebt","zhjteq","hmewdc","kfjbwbjz","sejivcxj","lggyhbqg","xiers","cohvlnydaa","rlchgdfg","fu","offiq","bhfz","eeerejo","fcvqkkcl","hj","fpy","fpyi","ruj","lx","fea","lmhzufedb","nustdwy","mlve","xvfsbsx","zavnboou","ulppfpfu","kqks","qlvqvevbvd","gzuerj","nricvjmtz","pqn","ftxku","ldycqfeh","gukds","jkg","dvav","nkdqw","epddr","ppc","aqnwgn","ynirkzvh","tdyqbhhcm","paivvutumo","ocvvtfd","a","iiphwih","ebpsbsb","vvlxbuyx","mravdaiobx","rhgrrnocsm","qnjcgno","cdrbs","utsjftbtd","gua","ymhem","qjjqcmljdb","gzz","kpwrdw","feydbxsz","zdbgpqw","orrcari","vwbymaz","rfgo","sjlugifygx","rwh","tmwr","bzijibe","pbjt","lxl","uyzlcyogs","bfxostvhoa","zc","ywmh","uwkppv","onirkzvh","wfp","calmdadivh","wwemy","icubmlltlx","kxmxcd","pnzynwu","vcwhtttte","xfefgw","vweg","esidmge","isukfuwni","yhcfa","swpmwxt","zdxvj","xtbd","mkya","txlalge","kx","musozy","nwsjs","quhj","dnnwvdgepk","todaq","aawwcd","xyrrfh","dxngst","seiqaapjoa","ycqalexmgf","tbuxghoyxu","livmehmgs","piau","znefqum","ghbfqdkfw","qzoxkrcyx","snmvazuxk","fpablytlob","sfotd","aqxjxfmwo","nipgzdyk","xjjscj","dhx","wglzsjxgh","rhpmmkzkuk","sxxoglio","zexutaueh","ejgo","xdyqbhhcm","uh","dkyyykjl","gs","dtyvo","auhj","gmvefxaqgp","gjtlnqw","busellldv","hlosnnjse","sxbqvu","jbzchfjg","zggjhv","ssobhdlq","izu","czawszp","acmm","rueetoduht","yai","ehrixnoym","uauxsyq","dv","wpqufo","vxb","wyk","dn","prm","gvhmxqrc","qhfhsmfnmn","rrtegsk","ancjtiwc","opdfryz","rzd","go","sqv","pcslhgk","uesiomipi","imwcipll","semvplwc","yzfwpd","wo","wu","gg","xxp","lvnuhnenqr","pqcd","vygy","zg","az","dcp","up","eokrohcs","wxkh","dpvie","jfihgvcojt","qubwbt","hilx","isqespk","jvd","ase","fmyhblsie","jpumrltp","clkz","pbg","yougavi","tcqalexmgf","srg","woysrcpscd","vjhzalrzc","abcytmpy","kdtimkf","ctxbykvxh","jwg","qv","kzylnnr","hsdq","tj","enkm","aktbbogxca","bcldf","bjmpxap","gkegfw","czrnpfgpyf","cjzsthlho","seotapc","qacat","fits","kja","kuvc","fdblpnc","lexsgyfxvf","njyfectif","tw","vvvk","pxdx","hnmrfeyz","tulsgxi","blmvcjyy","qebl","zomtagt","yoh","kss","ctwgzdxxf","fpans","nrcfmjmxkv","ymxgojqmp","ppvdb","lnctrm","kptk","uhw","ewyqdfs","qsq","baredwokc","xhrwreqhvt","hrzprqqiaq","jzenbdamqf","cskzchc","thplyfvfd","llwtibb","ehvnz","mf","ojjn","yo","tb","axxpab","wrif","tmdcstw","soproiwv","mr","ltn","pziigx","dlmyf","sswhjmbt","zqqath","lkaimnoisl","uki","tezahtgfx","jg","kcetiipr","iaq","wbkyrvrz","nlzpcwmhq","xaayhpehj","tdblpnc","zyvq","jiag","fqs","rwckrken","qmcokf","nwqzixuue","ddjyclox","yj","wcad","zz","aclpl","minvaoejml","kxiyvgfke","owfehhmf","lq","ss","lf","ioq","dwtuycxiba","ah","cbbx","lazcwq","ic","yyecqsct","qhzzidkkk","yegjbc","euwo","phrixnoym","ibadmq","nlgt","rmkii","auvfnzvsx","hhwhvc","fw","peqjqmlo","jcmypgbvym","zpscea","fsohzpvzd","uoiqlkhv","ciohhdvmc","xo","nwnqudmgx","hdjyclox","oh","qvllfhctv","lyjagnzqrb","mkfrgpsvk","leydbxsz","qtthkv","nh","hriqlr","us","omttcqodww","vwpvw","rmr","ndaed","mcuwkslzgz","wnhqhk","pwj","bqzkudnd","hdl","mqv","ewctfi","jhmyuyhv","qrtegsk","oqq","udtthktzw","vic","ddyfzsygkp","bodkixc","kshjjte","voproiwv","rhmivnderj","gkbhmdu","zlkmze","txtor","nkmgit","luhavlfzrz","ktsjftbtd","lulkongs","udjyclox","fss","kcil","rsevus","fjvwpbtral","jxbjpsbes","izo","dckqhztoe","kcgnenkp","lisqvwitr","lamx","mabrwcpne","fkps","qydconh","ipwcuii","skzeahlaj","hql","tcbqbbjegy","noq","ixlwrsgtx","gruvx","xpd","mttr","bnnzerqb","zh","upddr","fdmj","tjyzacxx","fncndomho","jhhknmqeky","ho","lclkucy","mpqfbtz","nofvix","pswpbvifp","svzrw","tzpo","vw","pvm","eufh","mjrneghlgm","fhlteoqcr","qeydbxsz","wxqnhwwgal","meg","tpmnlm","wbbx","oywmm","ozpwew","viqurnrsa","xzbtos","kybsqhpgj","bnnjyl","fvcurs","tgqankyo","ugduf","mu","mljkwpjnv","zgxtq","ogt","bdblpnc","rr","lia","fkt","zzf","nxtfkhafrz","iwurx","rtxbykvxh","qzkewh","ygxy","birxjyzt","cviguxsfp","vfxgegtj","jce","xkqd","ex","aexwejzhq","ib","hzs","zrzb","zjsiuzyfhi","oefnynpoqh","msekgzow","lbuxghoyxu","flodfrer","qunuiu","psl","iyniryc","jj","voodarkvmj","rztzj","vxl","ikfgupsx","xqx","sdnbfnzn","fnyavwb","ognx","vhttehw","ytyvo","hcldf","wb","ypmfb","rj","gtxp","jtifrsm","wclkucy","hzkewh","mecjllmkvd","gq","nndqapnf","ntlqv","clyjkky","wfsebeoi","vbzchfjg","ycmypgbvym","vbdhijfpv","oivhi","zoozujzu","czjfchsb","tuqzaqnhrt","ija","ttlxcsfpp","fbmpigj","yzwdxouf","lnositmt","hshjjte","ftgxnoxjol","ubq","wwk","pstqvu","kegogrmlbi","ttcf","tja","mzg","qcxwelp","lenbe","caeeho","wnyavwb","wwyqdfs","oalvmcdmv","hnm","mrsteftlyp","njwiiyuv","jxwmvsaf","pwiu","eauyw","va","bxngst","bgqgxja","lclezrjtoo","yncjtiwc","qkggwbbjw","wjlugifygx","xiv","fzr","lvrtwopsu","jh","tebe","pvvfj","xi","virkikg","rnymcrfea","xuuproi","vrxu","swatrox","hym","rglq","jqhafg","tgyqesx","ugzoairw","kuuproi","fhlopmmy","apmnlm","nyqiaoy","fcz","ufuid","vkcshric","robsg","ankllpkpn","irjvvv","vllm","mdwec","arjssea","xevoh","fsrjks","jbecooa","tvv","npetsi","ggms","jwei","lutuwsa","tzhifarh","wjduvjyux","niag","embvf","jf","erftap","valjkywko","yvlxbuyx","iebxxkkg","appmtygo","gttr","ogohvrti","hfjmcnii","zyvgqp","rhiikm","mqy","aedetkvn","ttlaspe","lgatqijue","smdkehxqq","sobfwjlgcd","cztzhho","qsruq","htld","rmujusenyb","ctlhb","rx","rqzme","apscea","dsmkuo","yfev","ukpexetct","vylnexv","iuhhwmueq","fsjakfr","nrif","xrvkumzov","uzghcrzsi","lqv","buyycywx","xrhbjtgzfr","hliipi","ggiwefn","izb","cmkii","idgeewnnm","wrzrzlq","yokrohcs","edskdkas","xmmkfr","azdh","dlzoaoy","xrcjj","ij","novlsqazv","pgciuuozr","cakadj","iomtagt","yxtfkhafrz","habfmwnkj","esmraglawb","objytxx","yp","cllm","au","jtsjftbtd","hn","mfbvhpytkm","npdbtle","gimcgg","fxdxzfu","vcc","konfvzekys","kfxheh","rcjej","gayndr","dnjpj","kdblpnc","vjzsthlho","txj","hnositmt","ly","hea","ufxgegtj","dsutndar","duberjm","lnr","tylnexv","mlxnxbhxn","me","noxelz","duvfnzvsx","eubs","gawuyrjb","miohhdvmc","yhvdajuf","mohvlnydaa","rxzftzlh","twt","gulcbvo","ktv","vs","cfjg","shmcpqx","rve","gfz","poqebmg","mbbeviftb","poczc","hjaumx","omewdc","crt","akeheyy","rhfhsmfnmn","dqhdlbs","fqljgcpq","fpwqnfbq","nimh","bwxlytdl","zj","pperqac","noiqlkhv","girfbpsn","hdbqvwu","bzb","sxtotnjmc","zmzv","dqa","cgfisboyoe","kqzenum","bl","ur","ote","aldt","smdcxrznt","jjbgqjvsf","spio","dckfyfqinf","nav","uqfdcie","kabtwtw","wuighlrm","zuv","yqp","ejaiuuuup","neho","yfvnahuovs","dbfpexas","icy","nkaoka","wcckmlutz","jnudftcll","ws","lkooauhjk","pgwiztdghf","ddvk","ze","mcii","yxbqvu","dacppfv","pf","putuwsa","lmldvs","zxdkzpm","uom","gicvfsvj","cdqvbbnj","blebfhlgm","yfxnar","oa","jgbbmzorci","thq","misp","vuqzaqnhrt","mzw","jhaiwhvjxs","ldqtygwg","qzmndcsl","rnszlyx","esuoder","mlfj","zzgeoekikh","wf","tnrk","ymq","vbr","hwurx","rhyj","vqfgwqmwe","qzaktqgy","tqrs","jwve","vofrqql","rkuzfcsffo","wypeqi","bqx","bnhqhk","buq","vqsxi","ybzuzt","apg","ivdysog","ojil","khm","ffsriq","sagd","binmlds","aein","eiyl","qaxjtgw","vgja","moocdmqvlv","scyepbb","seuh","mm","xfvfstxwjg","moqebmg","tnryozgsw","foym","pw","ronjprjpk","kcql","enzjn","rlmezyvxf","vvpa","aomfjmfay","ezqqrtppz","tn","pz","qifma","oxvj","duhj","xuda","zgzwl","gdnbfnzn","jhgdeftrlu","lmyffc","rln","edpwwc","gt","tawwcd","gjmpxap","axfes","qamx","obo","gffiq","gooexg","ii","uxiee","st","xrt","qnluwotgag","ejfzlqu","rnf","kzghcrzsi","gxqdaeaor","lo","wkcbwqlh","ryswpoxtj","uomc","aulcbvo","wsowqbswbv","vrwju","shibny","raqai","hjgv","ue","lmewdc","iki","ipst","ignzmncd","kttr","vwfmcgtjd","ttkeqlhac","qexvkzb","sxdkwuoq","vm","kluwzszk","xyr","swg","ckrdzcxp","ygh","kqrqp","lbzbqitnj","czzu","hspe","lougavi","vkm","aakdvuqfd","noym","dufh","dwwrm","gnryozgsw","djhpzwxx","zfbx","gzronf","eomximaqjg","tg","ixmtdqt","zsq","rwy","oimcgg","tthefhuz","kouqsojqra","wjx","ckaagivh","sclpl","vqozkhcn","byilhon","dpuxzwe","xav","fwrko","zphe","av","arehheknmb","uxttx","espe","ptxp","fe","hxl","xhrbzy","emd","alalbd","udl","jnbzaczqz","bbzchfjg","ywojfsu","tuhj","xjswcg","scmabujdp","oweg","ipawhkg","ohidv","suc","zpvnsosrhk","jesluhld","aiqluthkrk","uzvpxyw","mlc","zesluhld","opmsm","rpuzzas","hln","bcmdx","zbh","iik","yoc","eeadn","oiqumtudjn","cosdaerty","abzw","cffiq","bv","pkoqf","bwiucvb","tldcfhowl","cmfhsy","wqsuy","lgrxttbnk","iigvztvab","rendzhopt","npl","jbradz","xpcggy","eiwnwf","bd","vvmtybl","fvaswc","lkd","wyumbe" };
	int out = 6;

	Solution s;
	int res = s.distinctNames(ideas);

	cout << "Output: " << (out == res) << endl;
	getchar();
	return 0;
}