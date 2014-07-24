#include <string.h>
#include <stdio.h>
#include <proto/dos.h>

static void testvalue(CONST_STRPTR var, STRPTR expval, ULONG explen, BOOL expnull, LONG cnt)
{
    TEXT buffer[10];
    LONG len;
    struct LocalVar * lv;

    if ((len = GetVar(var, buffer, sizeof(buffer), 0)) < 0)
        printf("test %d ERROR getvar %d\n", cnt, (int)len);
    else
        printf("test %d getvar '%s'\n", cnt, buffer);
    if ((lv = FindVar(var, 0)) == NULL)
        printf("test %d ERROR findvar\n", cnt);
    else
        printf("test %d findvar lv_Value=%p, lv_Len=%d\n", cnt, lv->lv_Value, lv->lv_Len);
    if (lv->lv_Len != explen)
        printf("test %d ERROR lv_Len, expected %d, found %d\n", cnt, explen, lv->lv_Len);
    if (expnull && lv->lv_Value != NULL)
        printf("test %d ERROR lv_Value expected NULL, found %p\n", cnt, lv->lv_Value);

    if (!expnull && lv->lv_Value == NULL)
        printf("test %d ERROR lv_Value expected not NULL, found %p\n", cnt, lv->lv_Value);
}

int main(void)
{
       CONST_STRPTR var="abc";
       STRPTR val="cde";
       LONG cnt = 1;

       /* Behavior validated with OS3.x */

       printf("test %d setvar '%s'\n", cnt, val);
       if (SetVar(var, val, strlen(val), 0) == DOSFALSE)
               printf("error setvar\n");
       testvalue(var, val, 3, FALSE, cnt++);

       val="";
       printf("test %d setvar '%s'\n", cnt, val);
       if (SetVar(var, val, strlen(val), 0) == DOSFALSE)
               printf("error setvar\n");
       testvalue(var, val, 0, TRUE, cnt++);

       val="abcd";
       printf("test %d setvar '%s'\n", cnt, val);
       if (SetVar(var, val, strlen(val), 0) == DOSFALSE)
               printf("error setvar\n");
       testvalue(var, val, 4, FALSE, cnt++);

       val="";
       printf("test %d setvar '%s'\n", cnt, val);
       if (SetVar(var, val, strlen(val), 0) == DOSFALSE)
               printf("error setvar\n");
       testvalue(var, val, 0, TRUE, cnt++);

       val="";
       printf("test %d setvar '%s'\n", cnt, val);
       if (SetVar(var, val, strlen(val), 0) == DOSFALSE)
               printf("error setvar\n");
       testvalue(var, val, 0, TRUE, cnt++);

       return 0;
}
