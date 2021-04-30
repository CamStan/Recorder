AC_DEFUN([RECORDER_AC_GOTCHA], [
  # preserve state of flags
  GOTCHA_OLD_CFLAGS=$CFLAGS
  # GOTCHA_OLD_LDFLAGS=$LDFLAGS
  GOTCHA_OLD_LIBS=$LIBS

  AC_MSG_CHECKING(if gotcha is wanted )
  AC_ARG_WITH([gotcha], [
    AC_HELP_STRING([--with-gotcha], [
      path to installed libgotcha])],
    [
      AC_MSG_RESULT(yes)
      GOTCHA_INCLUDE="-I${withval}/include"
      GOTCHA_LIBS="-L${withval}/lib64 -lgotcha"
      CFLAGS="$CFLAGS ${GOTCHA_CFLAGS}"
      LIBS="$LIBS ${GOTCHA_LIBS}" ],
    [
      with_gotcha=no
      AC_MSG_RESULT(no)
      AM_CONDITIONAL([HAVE_GOTCHA], [false])
    ]
  )

  AS_IF([test x$with_gotcha != xno], [
    AC_CHECK_LIB([gotcha], [gotcha_wrap],
      [
        AC_SUBST(GOTCHA_INCLUDE)
        AC_SUBST(GOTCHA_LIBS)
        AM_CONDITIONAL([HAVE_GOTCHA], [true])
      ],[
        AC_MSG_ERROR([Unable to find suitable libgotcha, use --with-gotcha=PATH])
        AM_CONDITIONAL([HAVE_GOTCHA], [false])
      ],
      []
    )]
  )

  # restore flags
  CFLAGS=$GOTCHA_OLD_CFLAGS
  LIBS=$GOTCHA_OLD_LIBS
  # LDFLAGS=$GOTCHA_OLD_LDFLAGS
])
