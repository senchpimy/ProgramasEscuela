def fuct(S,A):
    if len(S)!=len(A):return "no coinciden"
    text=S[0]
    index=A[0]
    for _ in range(len(S)):
        text=text+S[index]
        index=A[index]
        if index==0:return text;

    return text

print(fuct("cdeo",[3,2,0,1]))
print(fuct("cdeenetpi",[5,2,0,1,6,4,8,3,7]))
print(fuct("bytdag",[4,3,0,1,2,5]))
