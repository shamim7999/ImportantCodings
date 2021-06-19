int BinaryExpo(int base, int po)
{
	int res = 1;
	while(po>0)
    	(po&1) ? (res*=base, --po) : (base*=base, po/=2);
    return res;
}
