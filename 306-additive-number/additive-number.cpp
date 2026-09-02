#define ll long long int
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int N=num.size();
        for (int flen=1;flen<=N/2;flen++){
            if (num[0]=='0' && flen>1) break;
                for (int slen=1;N-flen-slen>=max(flen,slen);slen++){
                    if (num[flen]=='0' && slen>1) break;
                    ll fnum = stoll(num.substr(0,flen));
                    ll snum = stoll(num.substr(flen,slen));
                    string bal = num.substr(flen+slen,N);
                    while (bal.size()>0){
                        ll tnum=fnum+snum;
                        string tstr=to_string(tnum);
                        if (bal.find(tstr)==0){
                            bal=bal.substr(tstr.size());
                            fnum=snum;
                            snum=tnum;
                        }
                        else break;
                    }
                    if (bal.size()==0){
                        return true;
                    }
                }
            }
        return false;
    }
};