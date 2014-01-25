#include <ruby.h>

#define IS_GREEK(c) \
((unsigned char)*c == 206 || (unsigned char)*c == 207) && \
upperfix_map[((unsigned char)*c) - 206][(unsigned char)*(c + 1)][0]

VALUE upperfix(VALUE self, VALUE str);
void init_upperfix_map();

VALUE GreekStringUtils = Qnil;
unsigned char upperfix_map[2][256][2] = {{{0}}};

void
Init_upperfix()
{
    GreekStringUtils = rb_define_module("GreekStringUtils");
    init_upperfix_map();
    rb_define_method(GreekStringUtils, "upperfix", upperfix, 1);
}

VALUE
upperfix(VALUE self, VALUE str)
{
    char *s, *send;
    long len;

    str = StringValue(str);
    str = rb_funcall(str, rb_intern("upcase"), 0);

    s = RSTRING_PTR(str);
    send = RSTRING_END(str);
    len = RSTRING_LEN(str);

    if(len == 2)
        /* ή -> Ή */
        upperfix_map[0][174][1] = 137;

    while (s < send)
        if(IS_GREEK(s)) {
            unsigned char b1 = (unsigned char)*s, b2 = (unsigned char)*(s + 1);

            s[0] = (char)upperfix_map[b1 - 206][b2][0];
            s[1] = (char)upperfix_map[b1 - 206][b2][1];
            s += 2;
        }
        else
            s++;

    if (len == 2)
        upperfix_map[0][174][1] = 151;

    return str;
}

void
init_upperfix_map()
{
    /* α -> Α */
    upperfix_map[0][177][0] = 206;
    upperfix_map[0][177][1] = 145;

    /* β -> Β */
    upperfix_map[0][178][0] = 206;
    upperfix_map[0][178][1] = 146;

    /* γ -> Γ */
    upperfix_map[0][179][0] = 206;
    upperfix_map[0][179][1] = 147;

    /* δ -> Δ */
    upperfix_map[0][180][0] = 206;
    upperfix_map[0][180][1] = 148;

    /* ε -> Ε */
    upperfix_map[0][181][0] = 206;
    upperfix_map[0][181][1] = 149;

    /* ζ -> Ζ */
    upperfix_map[0][182][0] = 206;
    upperfix_map[0][182][1] = 150;

    /* η -> Η */
    upperfix_map[0][183][0] = 206;
    upperfix_map[0][183][1] = 151;

    /* θ -> Θ */
    upperfix_map[0][184][0] = 206;
    upperfix_map[0][184][1] = 152;

    /* ι -> Ι */
    upperfix_map[0][185][0] = 206;
    upperfix_map[0][185][1] = 153;

    /* κ -> Κ */
    upperfix_map[0][186][0] = 206;
    upperfix_map[0][186][1] = 154;

    /* λ -> Λ */
    upperfix_map[0][187][0] = 206;
    upperfix_map[0][187][1] = 155;

    /* μ -> Μ */
    upperfix_map[0][188][0] = 206;
    upperfix_map[0][188][1] = 156;

    /* ν -> Ν */
    upperfix_map[0][189][0] = 206;
    upperfix_map[0][189][1] = 157;

    /* ξ -> Ξ */
    upperfix_map[0][190][0] = 206;
    upperfix_map[0][190][1] = 158;

    /* ο -> Ο */
    upperfix_map[0][191][0] = 206;
    upperfix_map[0][191][1] = 159;

    /* π -> Π */
    upperfix_map[1][128][0] = 206;
    upperfix_map[1][128][1] = 160;

    /* ρ -> Ρ */
    upperfix_map[1][129][0] = 206;
    upperfix_map[1][129][1] = 161;

    /* σ -> Σ */
    upperfix_map[1][131][0] = 206;
    upperfix_map[1][131][1] = 163;

    /* ς -> Σ */
    upperfix_map[1][130][0] = 206;
    upperfix_map[1][130][1] = 163;

    /* τ -> Τ */
    upperfix_map[1][132][0] = 206;
    upperfix_map[1][132][1] = 164;

    /* υ -> Υ */
    upperfix_map[1][133][0] = 206;
    upperfix_map[1][133][1] = 165;

    /* φ -> Φ */
    upperfix_map[1][134][0] = 206;
    upperfix_map[1][134][1] = 166;

    /* χ -> Χ */
    upperfix_map[1][135][0] = 206;
    upperfix_map[1][135][1] = 167;

    /* ψ -> Ψ */
    upperfix_map[1][136][0] = 206;
    upperfix_map[1][136][1] = 168;

    /* ω -> Ω */
    upperfix_map[1][137][0] = 206;
    upperfix_map[1][137][1] = 169;

    /* ά -> Α */
    upperfix_map[0][172][0] = 206;
    upperfix_map[0][172][1] = 145;

    /* έ -> Ε */
    upperfix_map[0][173][0] = 206;
    upperfix_map[0][173][1] = 149;

    /* ή -> H */
    upperfix_map[0][174][0] = 206;
    upperfix_map[0][174][1] = 151;

    /* ί -> Ι */
    upperfix_map[0][175][0] = 206;
    upperfix_map[0][175][1] = 153;

    /* ό -> Ο */
    upperfix_map[1][140][0] = 206;
    upperfix_map[1][140][1] = 159;

    /* ύ -> Υ */
    upperfix_map[1][141][0] = 206;
    upperfix_map[1][141][1] = 165;

    /* ώ -> Ω */
    upperfix_map[1][142][0] = 206;
    upperfix_map[1][142][1] = 169;

    /* Ά -> Α */
    upperfix_map[0][134][0] = 206;
    upperfix_map[0][134][1] = 145;

    /* Έ -> Ε */
    upperfix_map[0][136][0] = 206;
    upperfix_map[0][136][1] = 149;

    /* Ή -> Η */
    upperfix_map[0][137][0] = 206;
    upperfix_map[0][137][1] = 151;

    /* Ί -> Ι */
    upperfix_map[0][138][0] = 206;
    upperfix_map[0][138][1] = 153;

    /* Ό -> Ο */
    upperfix_map[0][140][0] = 206;
    upperfix_map[0][140][1] = 159;

    /* Ύ -> Υ */
    upperfix_map[0][142][0] = 206;
    upperfix_map[0][142][1] = 165;

    /* Ώ -> Ω */
    upperfix_map[0][143][0] = 206;
    upperfix_map[0][143][1] = 169;

    /* ϊ -> Ϊ */
    upperfix_map[1][138][0] = 206;
    upperfix_map[1][138][1] = 170;

    /* ϋ -> Ϋ */
    upperfix_map[1][139][0] = 206;
    upperfix_map[1][139][1] = 171;

    /* ΐ -> Ϊ */
    upperfix_map[0][144][0] = 206;
    upperfix_map[0][144][1] = 170;

    /* ΰ -> Ϋ */
    upperfix_map[0][176][0] = 206;
    upperfix_map[0][176][1] = 171;
}
