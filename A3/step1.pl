% Julia Garant Fall 2021

% this order works
word(nfs, n,f,s). 	% V3
word(gnu, g,n,u).	% V4
word(xml, x,m,l).	% V5
word(mac, m,a,c).	% H3
word(sql, s,q,l).	% H4
word(web, w,e,b).	% H5
word(api, a,p,i).

word(perl, p,e,r,l).	% V1
word(java, j,a,v,a).
word(coop, c,o,o,p).
word(loop, l,o,o,p).
word(fork, f,o,r,k).
word(fifo, f,i,f,o).
word(pipe, p,i,p,e).

word(emacs, e,m,a,c,s). % V6
word(linux, l,i,n,u,x).	% H2
word(mouse, m,o,u,s,e).

word(online, o,n,l,i,n,e).	% V2
word(prolog, p,r,o,l,o,g).	%H1
word(google, g,o,o,g,l,e).
word(python, p,y,t,h,o,n).
word(parser, p,a,r,s,e,r).
word(kernel, k,e,r,n,e,l).

% rearranging the order works 
% it will give discontiguous error

crossword(V1, V2, V3, V4, V5, V6, H1, H2, H3, H4, H5) :-
    % First variable is the word, rest are chars
   	word(V1, V1aH1a, _, _, _), %Perl
   	word(V2, V2aH1c, _, V2cH2a, _, _, V2fH5b), %OnLinE
   	word(V3, V3aH2c, _, V3cH4a), %NfS
   	word(V4, V4aH1f, _, V4cH2d), %GnU
    word(V5, V5aH2e, V5bH3a,V5cH4c), %XML
    word(V6, _, _, _, V6dH3c, _), %emaCs
    
   	word(H1, V1aH1a, _, V2aH1c, _, _, V4aH1f), %PrOloG
   	word(H2, V2cH2a, _, V3aH2c, V4cH2d, V5aH2e), %LiNUX
   	word(H3, V5bH3a, _, V6dH3c), %MaC
    word(H4, V3cH4a, _, V5cH4c), %SqL
    word(H5, _, V2fH5b, _), %wEb
    
    V1 \=  H1.



