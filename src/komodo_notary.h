/******************************************************************************
 * Copyright © 2014-2016 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

const char *Notaries_genesis[][2] =
{
    { "jl777_testA", "03b7621b44118017a16043f19b30cc8a4cfe068ac4e42417bae16ba460c80f3828" },
    { "jl777_testB", "02ebfc784a4ba768aad88d44d1045d240d47b26e248cafaf1c5169a42d7a61d344" },
    { "pondsea_SH", "02209073bc0943451498de57f802650311b1f12aa6deffcd893da198a544c04f36" },
    { "crackers_EU", "0340c66cf2c41c41efb420af57867baa765e8468c12aa996bfd816e1e07e410728" },
    { "pondsea_EU", "0225aa6f6f19e543180b31153d9e6d55d41bc7ec2ba191fd29f19a2f973544e29d" },
    { "locomb_EU", "025c6d26649b9d397e63323d96db42a9d3caad82e1d6076970efe5056c00c0779b" },
    { "fullmoon_AE", "0204a908350b8142698fdb6fabefc97fe0e04f537adc7522ba7a1e8f3bec003d4a" },
    { "movecrypto_EU", "021ab53bc6cf2c46b8a5456759f9d608966eff87384c2b52c0ac4cc8dd51e9cc42" },
    { "badass_EU", "0209d48554768dd8dada988b98aca23405057ac4b5b46838a9378b95c3e79b9b9e" },
    { "crackers_NA", "029e1c01131974f4cd3f564cc0c00eb87a0f9721043fbc1ca60f9bd0a1f73f64a1" },
    { "proto_EU", "03681ffdf17c8f4f0008cefb7fa0779c5e888339cdf932f0974483787a4d6747c1" },
    { "jeezy_EU", "023cb3e593fb85c5659688528e9a4f1c4c7f19206edc7e517d20f794ba686fd6d6" },
    { "farl4web_EU", "035caa40684ace968677dca3f09098aa02b70e533da32390a7654c626e0cf908e1" },
    { "nxtswe_EU", "032fb104e5eaa704a38a52c126af8f67e870d70f82977e5b2f093d5c1c21ae5899" },
    { "traderbill_EU", "03196e8de3e2e5d872f31d79d6a859c8704a2198baf0af9c7b21e29656a7eb455f" },
    { "vanbreuk_EU", "024f3cad7601d2399c131fd070e797d9cd8533868685ddbe515daa53c2e26004c3" },
    { "titomane_EU", "03517fcac101fed480ae4f2caf775560065957930d8c1facc83e30077e45bdd199" },
    { "supernet_AE", "029d93ef78197dc93892d2a30e5a54865f41e0ca3ab7eb8e3dcbc59c8756b6e355" },
    { "supernet_EU", "02061c6278b91fd4ac5cab4401100ffa3b2d5a277e8f71db23401cc071b3665546" },
    { "supernet_NA", "033c073366152b6b01535e15dd966a3a8039169584d06e27d92a69889b720d44e1" },
    { "yassin_EU", "033fb7231bb66484081952890d9a03f91164fb27d392d9152ec41336b71b15fbd0" },
    { "durerus_EU", "02bcbd287670bdca2c31e5d50130adb5dea1b53198f18abeec7211825f47485d57" },
    { "badass_SH", "026b49dd3923b78a592c1b475f208e23698d3f085c4c3b4906a59faf659fd9530b" },
    { "badass_NA", "02afa1a9f948e1634a29dc718d218e9d150c531cfa852843a1643a02184a63c1a7" },
    { "pondsea_NA", "031bcfdbb62268e2ff8dfffeb9ddff7fe95fca46778c77eebff9c3829dfa1bb411" },
    { "rnr_EU", "0287aa4b73988ba26cf6565d815786caf0d2c4af704d7883d163ee89cd9977edec" },
    { "crackers_SH", "02313d72f9a16055737e14cfc528dcd5d0ef094cfce23d0348fe974b6b1a32e5f0" },
    { "grewal_SH", "03212a73f5d38a675ee3cdc6e82542a96c38c3d1c79d25a1ed2e42fcf6a8be4e68" },
    { "polycryptoblock_NA", "02708dcda7c45fb54b78469673c2587bfdd126e381654819c4c23df0e00b679622" },
    { "titomane_NA", "0387046d9745414fb58a0fa3599078af5073e10347e4657ef7259a99cb4f10ad47" },
    { "titomane_AE", "03cda6ca5c2d02db201488a54a548dbfc10533bdc275d5ea11928e8d6ab33c2185" },
    { "kolo_EU", "03f5c08dadffa0ffcafb8dd7ffc38c22887bd02702a6c9ac3440deddcf2837692b" },
    { "artik_NA", "0224e31f93eff0cc30eaf0b2389fbc591085c0e122c4d11862c1729d090106c842" },
    { "eclips_EU", "0339369c1f5a2028d44be7be6f8ec3b907fdec814f87d2dead97cab4edb71a42e9" },
    { "titomane_SH", "035f49d7a308dd9a209e894321f010d21b7793461b0c89d6d9231a3fe5f68d9960" },
};

int32_t komodo_ratify_threshold(int32_t height,uint64_t signedmask)
{
    int32_t htind,numnotaries,i,wt = 0;
    htind = height / KOMODO_ELECTION_GAP;
    numnotaries = Pubkeys[htind].numnotaries;
    for (i=0; i<numnotaries; i++)
        if ( ((1LL << i) & signedmask) != 0 )
            wt++;
    if ( wt > (numnotaries >> 1) || (wt > 7 && (signedmask & 1) != 0) )
        return(1);
    else return(0);
}

int32_t komodo_notaries(uint8_t pubkeys[64][33],int32_t height)
{
    int32_t i,htind,n; uint64_t mask = 0; struct knotary_entry *kp,*tmp;
    htind = height / KOMODO_ELECTION_GAP;
    pthread_mutex_lock(&komodo_mutex);
    n = Pubkeys[htind].numnotaries;
    HASH_ITER(hh,Pubkeys[htind].Notaries,kp,tmp)
    {
        if ( kp->notaryid < n )
        {
            mask |= (1LL << kp->notaryid);
            memcpy(pubkeys[kp->notaryid],kp->pubkey,33);
        } else printf("illegal notaryid.%d vs n.%d\n",kp->notaryid,n);
    }
    pthread_mutex_unlock(&komodo_mutex);
    if ( (n < 64 && mask == ((1LL << n)-1)) || (n == 64 && mask == 0xffffffffffffffffLL) )
        return(n);
    printf("error retrieving notaries ht.%d got mask.%llx for n.%d\n",height,(long long)mask,n);
    return(-1);
}

void komodo_notarysinit(int32_t origheight,uint8_t pubkeys[64][33],int32_t num)
{
    static int32_t hwmheight;
    int32_t k,i,htind,nonz,height; struct knotary_entry *kp; struct knotaries_entry N;
    if ( Pubkeys == 0 )
        Pubkeys = (struct knotaries_entry *)calloc(KOMODO_MAXBLOCKS / KOMODO_ELECTION_GAP,sizeof(*Pubkeys));
    memset(&N,0,sizeof(N));
    if ( origheight > 0 )
    {
        height = (origheight + KOMODO_ELECTION_GAP/2);
        height /= KOMODO_ELECTION_GAP;
        height = ((height + 1) * KOMODO_ELECTION_GAP);
        htind = (height / KOMODO_ELECTION_GAP);
        printf("htind.%d activation %d from %d vs %d | hwmheight.%d\n",htind,height,origheight,(((origheight+KOMODO_ELECTION_GAP/2)/KOMODO_ELECTION_GAP)+1)*KOMODO_ELECTION_GAP,hwmheight);
    } else htind = 0;
    pthread_mutex_lock(&komodo_mutex);
    for (k=0; k<num; k++)
    {
        kp = (struct knotary_entry *)calloc(1,sizeof(*kp));
        memcpy(kp->pubkey,pubkeys[k],33);
        kp->notaryid = k;
        HASH_ADD_KEYPTR(hh,N.Notaries,kp->pubkey,33,kp);
        if ( height > 0 )
        {
            for (i=0; i<33; i++)
                printf("%02x",pubkeys[k][i]);
            printf(" notarypubs.[%d] ht.%d active at %d\n",k,origheight,htind*KOMODO_ELECTION_GAP);
        }
    }
    N.numnotaries = num;
    for (i=htind; i<KOMODO_MAXBLOCKS / KOMODO_ELECTION_GAP; i++)
    {
        if ( Pubkeys[i].height != 0 && origheight < hwmheight )
        {
            printf("Pubkeys[%d].height %d < %d hwmheight, origheight.%d\n",i,Pubkeys[i].height,hwmheight,origheight);
            break;
        }
        Pubkeys[i] = N;
        Pubkeys[i].height = i * KOMODO_ELECTION_GAP;
    }
    pthread_mutex_unlock(&komodo_mutex);
    if ( origheight > hwmheight )
        hwmheight = origheight;
}

int32_t komodo_chosennotary(int32_t *notaryidp,int32_t height,uint8_t *pubkey33)
{
    // -1 if not notary, 0 if notary, 1 if special notary
    struct knotary_entry *kp; int32_t numnotaries=0,htind,modval = -1;
    *notaryidp = -1;
    if ( height < 0 || height >= KOMODO_MAXBLOCKS )
    {
        printf("komodo_chosennotary ht.%d illegal\n",height);
        return(-1);
    }
    htind = height / KOMODO_ELECTION_GAP;
    pthread_mutex_lock(&komodo_mutex);
    HASH_FIND(hh,Pubkeys[htind].Notaries,pubkey33,33,kp);
    pthread_mutex_unlock(&komodo_mutex);
    if ( kp != 0 )
    {
        if ( (numnotaries= Pubkeys[htind].numnotaries) > 0 )
        {
            *notaryidp = kp->notaryid;
            modval = ((height % numnotaries) == kp->notaryid);
            //printf("found notary.%d ht.%d modval.%d\n",kp->notaryid,height,modval);
        } else printf("unexpected zero notaries at height.%d\n",height);
    }
    //int32_t i; for (i=0; i<33; i++)
    //    printf("%02x",pubkey33[i]);
    //printf(" ht.%d notary.%d special.%d htind.%d num.%d\n",height,*notaryidp,modval,htind,numnotaries);
    return(modval);
}

void komodo_notarized_update(struct komodo_state *sp,int32_t nHeight,int32_t notarized_height,uint256 notarized_hash,uint256 notarized_desttxid)
{
    struct notarized_checkpoint *np;
    if ( notarized_height > nHeight )
    {
        printf("komodo_notarized_update REJECT notarized_height %d > %d nHeight\n",notarized_height,nHeight);
        return;
    }
    sp->NPOINTS = (struct notarized_checkpoint *)realloc(sp->NPOINTS,(sp->NUM_NPOINTS+1) * sizeof(*sp->NPOINTS));
    np = &sp->NPOINTS[sp->NUM_NPOINTS++];
    memset(np,0,sizeof(*np));
    np->nHeight = nHeight;
    sp->NOTARIZED_HEIGHT = np->notarized_height = notarized_height;
    sp->NOTARIZED_HASH = np->notarized_hash = notarized_hash;
    sp->NOTARIZED_DESTTXID = np->notarized_desttxid = notarized_desttxid;
}

//struct komodo_state *komodo_stateptr(char *symbol,char *dest);
int32_t komodo_notarized_height(uint256 *hashp,uint256 *txidp)
{
    char symbol[16],dest[16]; struct komodo_state *sp;
    if ( (sp= komodo_stateptr(symbol,dest)) != 0 )
    {
        *hashp = sp->NOTARIZED_HASH;
        *txidp = sp->NOTARIZED_DESTTXID;
        return(sp->NOTARIZED_HEIGHT);
    }
    else
    {
        memset(hashp,0,sizeof(*hashp));
        memset(txidp,0,sizeof(*txidp));
        return(0);
    }
}

int32_t komodo_notarizeddata(int32_t nHeight,uint256 *notarized_hashp,uint256 *notarized_desttxidp)
{
    struct notarized_checkpoint *np = 0; int32_t i; char symbol[16],dest[16]; struct komodo_state *sp;
    if ( (sp= komodo_stateptr(symbol,dest)) != 0 )
    {
        if ( sp->NUM_NPOINTS > 0 )
        {
            for (i=0; i<sp->NUM_NPOINTS; i++)
            {
                if ( sp->NPOINTS[i].nHeight >= nHeight )
                    break;
                np = &sp->NPOINTS[i];
            }
        }
        if ( np != 0 )
        {
            *notarized_hashp = np->notarized_hash;
            *notarized_desttxidp = np->notarized_desttxid;
            return(np->notarized_height);
        }
    }
    memset(notarized_hashp,0,sizeof(*notarized_hashp));
    return(0);
}

void komodo_init(int32_t height)
{
    static int didinit; uint256 zero; int32_t i,k,n; uint8_t pubkeys[64][33];
    if ( didinit == 0 )
    {
        pthread_mutex_init(&komodo_mutex,NULL);
        decode_hex(NOTARY_PUBKEY33,33,(char *)NOTARY_PUBKEY.c_str());
        if ( height >= 0 )
        {
            n = (int32_t)(sizeof(Notaries_genesis)/sizeof(*Notaries_genesis));
            for (k=0; k<n; k++)
            {
                if ( Notaries_genesis[k][0] == 0 || Notaries_genesis[k][1] == 0 || Notaries_genesis[k][0][0] == 0 || Notaries_genesis[k][1][0] == 0 )
                    break;
                decode_hex(pubkeys[k],33,(char *)Notaries_genesis[k][1]);
            }
            komodo_notarysinit(0,pubkeys,k);
        }
        memset(&zero,0,sizeof(zero));
        //for (i=0; i<sizeof(Minerids); i++)
        //    Minerids[i] = -2;
        didinit = 1;
    }
    komodo_stateupdate(0,0,0,0,zero,0,0,0,0,0,0,0,0,0,0);
}

void komodo_assetchain_pubkeys(char *jsonstr)
{
    cJSON *array; int32_t i,n; uint8_t pubkeys[64][33]; char *hexstr;
    memset(pubkeys,0,sizeof(pubkeys));
    if ( (array= cJSON_Parse(jsonstr)) != 0 )
    {
        if ( (n= cJSON_GetArraySize(array)) > 0 )
        {
            for (i=0; i<n; i++)
            {
                if ( (hexstr= jstri(array,i)) != 0 && is_hexstr(hexstr,0) == 66 )
                {
                    decode_hex(pubkeys[i],33,hexstr);
                    fprintf(stderr,"i.%d of n.%d pubkey.(%s)\n",i,n,hexstr);
                }
                else
                {
                    fprintf(stderr,"illegal hexstr.(%s) i.%d of n.%d\n",hexstr,i,n);
                    break;
                }
            }
            if ( i == n )
            {
                komodo_init(-1);
                komodo_notarysinit(0,pubkeys,n);
                KOMODO_EXTERNAL_NOTARIES = 1;
                //printf("initialize pubkeys[%d]\n",n);
            } else fprintf(stderr,"komodo_assetchain_pubkeys i.%d vs n.%d\n",i,n);
        } else fprintf(stderr,"assetchain pubkeys n.%d\n",n);
    }
    //else if ( jsonstr != 0 )
    //    fprintf(stderr,"assetchain pubkeys couldnt parse.(%s)\n",jsonstr);
}
