/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted for any purpose (including commercial purposes)
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    and/or materials provided with the distribution.
 *
 * 3. In addition, redistributions of modified forms of the source or binary
 *    code must carry prominent notices stating that the original code was
 *    changed and the date of the change.
 *
 * 4. All publications or advertising materials mentioning features or use of
 *    this software are asked, but not required, to acknowledge that it was
 *    developed by The HDF Group and by the National Center for Supercomputing
 *    Applications at the University of Illinois at Urbana-Champaign and
 *    credit the contributors.
 *
 * 5. Neither the name of The HDF Group, the name of the University, nor the
 *    name of any Contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission from
 *    The HDF Group, the University, or the Contributor, respectively.
 *
 * DISCLAIMER:
 * THIS SOFTWARE IS PROVIDED BY THE HDF GROUP AND THE CONTRIBUTORS
 * "AS IS" WITH NO WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED. In no
 * event shall The HDF Group or the Contributors be liable for any damages
 * suffered by the users arising out of the use of this software, even if
 * advised of the possibility of such damage.
 *
 * Portions of Recorder were developed with support from the Lawrence Berkeley
 * National Laboratory (LBNL) and the United States Department of Energy under
 * Prime Contract No. DE-AC02-05CH11231.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "recorder.h"
#include <gotcha/gotcha.h>

/* define gotcha-specific state to use with our wrapper */
#define RECORDER_DEF(name, ret, args, argnames) \
gotcha_wrappee_handle_t wrappee_handle_ ## name; \
ret (*__real_ ## name) args = NULL;

RECORDER_DEF(PMPI_Init, int,
            (int* argc, char ***argv),
            (argc, argv))
RECORDER_DEF(PMPI_Init_thread, int,
            (int* argc, char ***argv, int required, int* provided),
            (argc, argv, required, provided))
RECORDER_DEF(PMPI_Finalize, int,
            (),
            ())
RECORDER_DEF(PMPI_Comm_size, int,
            (MPI_Comm comm, int* size),
            (comm, size))
RECORDER_DEF(PMPI_Comm_rank, int,
            (MPI_Comm comm, int* rank),
            (comm, rank))
RECORDER_DEF(PMPI_Wtime, double,
            (),
            ())
RECORDER_DEF(PMPI_Reduce, int,
            (const void* sbuf, void* rbuf, int count, MPI_Datatype stype, MPI_Op op, int root, MPI_Comm comm),
            (sbuf, rbuf, count, stype, op, root, comm))
RECORDER_DEF(access, int,
            (const char* path, int mode),
            (path, mode))
#if 0
RECORDER_DEF(chmod, int,
            (const char* path, mode_t mode),
            (path, mode))
#endif
RECORDER_DEF(mkdir, int,
            (const char* path, mode_t mode),
            (path, mode))
#if 0
RECORDER_DEF(rmdir, int,
            (const char* path),
            (path))
RECORDER_DEF(chdir, int,
            (const char* path),
            (path))
RECORDER_DEF(__getcwd_chk, char*,
            (char* path, size_t size, size_t buflen),
            (path, size, buflen))
RECORDER_DEF(getcwd, char*,
            (char* path, size_t size),
            (path, size))
RECORDER_DEF(getwd, char*,
            (char* path),
            (path))
RECORDER_DEF(get_current_dir_name, char*,
            (void),
            ())
RECORDER_DEF(rename, int,
            (const char* oldpath, const char* newpath),
            (oldpath, newpath))
RECORDER_DEF(truncate, int,
            (const char* path, off_t length),
            (path, length))
RECORDER_DEF(unlink, int,
            (const char* path),
            (path))
#endif
RECORDER_DEF(remove, int,
            (const char* path),
            (path))
#if 0

RECORDER_DEF(stat, int,
            (const char* path, struct stat* buf),
            (path, buf))
RECORDER_DEF(fstat, int,
            (int fd, struct stat* buf),
            (fd, buf))
RECORDER_DEF(__xstat, int,
            (int vers, const char* path, struct stat* buf),
            (vers, path, buf))
RECORDER_DEF(__fxstat, int,
            (int vers, int fd, struct stat* buf),
            (vers, fd, buf))
RECORDER_DEF(__lxstat, int,
            (int vers, const char* path, struct stat* buf),
            (vers, path, buf))
RECORDER_DEF(statfs, int,
            (const char* path, struct statfs* fsbuf),
            (path, fsbuf))
RECORDER_DEF(fstatfs, int,
            (int fd, struct statfs* fsbuf),
            (fd, fsbuf))

RECORDER_DEF(creat, int,
            (const char* path, mode_t mode),
            (path, mode))
RECORDER_DEF(creat64, int,
            (const char* path, mode_t mode),
            (path, mode))
#endif
RECORDER_DEF(open, int,
            (const char* path, int flags, ...),
            (path, flags))
#if 0
RECORDER_DEF(open64, int,
            (const char* path, int flags, ...),
            (path, flags))
RECORDER_DEF(__open_2, int,
            (const char* path, int flags, ...),
            (path, flags))

#ifdef HAVE_LIO_LISTIO
RECORDER_DEF(lio_listio, int,
            (int m, struct aiocb* const cblist[], int n, struct sigevent* sep),
            (m, cblist, n, sep))
#endif

RECORDER_DEF(lseek, off_t,
            (int fd, off_t offset, int whence),
            (fd, offset, whence))
RECORDER_DEF(lseek64, off64_t,
            (int fd, off64_t offset, int whence),
            (fd, offset, whence))

RECORDER_DEF(posix_fadvise, int,
            (int fd, off_t offset, off_t len, int advice),
            (fd, offset, len, advice))

RECORDER_DEF(read, ssize_t,
            (int fd, void* buf, size_t count),
            (fd, buf, count))
RECORDER_DEF(write, ssize_t,
            (int fd, const void* buf, size_t count),
            (fd, buf, count))
RECORDER_DEF(readv, ssize_t,
            (int fd, const struct iovec* iov, int iovcnt),
            (fd, iov, iovcnt))
RECORDER_DEF(writev, ssize_t,
            (int fd, const struct iovec* iov, int iovcnt),
            (fd, iov, iovcnt))
RECORDER_DEF(pread, ssize_t,
            (int fd, void* buf, size_t count, off_t off),
            (fd, buf, count, off))
RECORDER_DEF(pread64, ssize_t,
            (int fd, void* buf, size_t count, off64_t off),
            (fd, buf, count, off))
RECORDER_DEF(pwrite, ssize_t,
            (int fd, const void* buf, size_t count, off_t off),
            (fd, buf, count, off))
RECORDER_DEF(pwrite64, ssize_t,
            (int fd, const void* buf, size_t count, off64_t off),
            (fd, buf, count, off))
#endif
RECORDER_DEF(close, int,
            (int fd),
            (fd))
#if 0
RECORDER_DEF(fchdir, int,
            (int fd),
            (fd))
RECORDER_DEF(ftruncate, int,
            (int fd, off_t length),
            (fd, length))
RECORDER_DEF(fsync, int,
            (int fd),
            (fd))
RECORDER_DEF(fdatasync, int,
            (int fd),
            (fd))
RECORDER_DEF(flock, int,
            (int fd, int operation),
            (fd, operation))
RECORDER_DEF(fchmod, int,
            (int fd, mode_t mode),
            (fd, mode))

RECORDER_DEF(mmap, void*,
            (void* addr, size_t len, int prot, int fl, int fd, off_t off),
            (addr, len, prot, fl, fd, off))
RECORDER_DEF(msync, int,
            (void* addr, size_t length, int flags),
            (addr, length, flags))
RECORDER_DEF(munmap, int,
            (void* addr, size_t length),
            (addr, length))
RECORDER_DEF(mmap64, void*,
            (void* addr, size_t len, int prot, int fl, int fd, off_t off),
            (addr, len, prot, fl, fd, off))

RECORDER_DEF(opendir, DIR*,
            (const char* name),
            (name))
RECORDER_DEF(fdopendir, DIR*,
            (int fd),
            (fd))
RECORDER_DEF(closedir, int,
            (DIR* dirp),
            (dirp))
RECORDER_DEF(readdir, struct dirent*,
            (DIR* dirp),
            (dirp))
RECORDER_DEF(rewinddir, void,
            (DIR* dirp),
            (dirp))
RECORDER_DEF(dirfd, int,
            (DIR* dirp),
            (dirp))
RECORDER_DEF(telldir, long,
            (DIR* dirp),
            (dirp))
RECORDER_DEF(scandir, int,
            (const char* dirp, struct dirent** namelist,
             int (*filter)(const struct dirent*),
             int (*compar)(const struct dirent**, const struct dirent**)),
            (dirp, namelist, filter, compar))
RECORDER_DEF(seekdir, void,
            (DIR* dirp, long loc),
            (dirp, loc))

#endif
RECORDER_DEF(fopen, FILE*,
            (const char* path, const char* mode),
            (path, mode))
#if 0
RECORDER_DEF(freopen, FILE*,
            (const char* path, const char* mode, FILE* stream),
            (path, mode, stream))
RECORDER_DEF(setvbuf, int,
            (FILE* stream, char* buf, int type, size_t size),
            (stream, buf, type, size))
RECORDER_DEF(setbuf, void,
            (FILE* stream, char* buf),
            (stream, buf))
RECORDER_DEF(ungetc, int,
            (int c, FILE* stream),
            (c, stream))
RECORDER_DEF(fgetc, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(fputc, int,
            (int c, FILE* stream),
            (c, stream))
RECORDER_DEF(getc, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(putc, int,
            (int c, FILE* stream),
            (c, stream))
RECORDER_DEF(fgets, char*,
            (char* s, int n, FILE* stream),
            (s, n, stream))
RECORDER_DEF(fputs, int,
            (const char* s, FILE* stream),
            (s, stream))
RECORDER_DEF(fread, size_t,
            (void* ptr, size_t size, size_t nitems, FILE* stream),
            (ptr, size, nitems, stream))
#endif
RECORDER_DEF(fwrite, size_t,
            (const void* ptr, size_t size, size_t nitems, FILE* stream),
            (ptr, size, nitems, stream))
#if 0
RECORDER_DEF(fprintf, int,
            (FILE* stream, const char* format, ...),
            (stream, format))
RECORDER_DEF(fscanf, int,
            (FILE* stream, const char* format, ...),
            (stream, format))
RECORDER_DEF(vfprintf, int,
            (FILE* stream, const char* format, va_list args),
            (stream, format, args))
RECORDER_DEF(vfscanf, int,
            (FILE* stream, const char* format, va_list args),
            (stream, format, args))
RECORDER_DEF(fseek, int,
            (FILE* stream, long offset, int whence),
            (stream, offset, whence))
RECORDER_DEF(fseeko, int,
            (FILE* stream, off_t offset, int whence),
            (stream, offset, whence))
RECORDER_DEF(ftell, long,
            (FILE* stream),
            (stream))
RECORDER_DEF(ftello, off_t,
            (FILE* stream),
            (stream))
RECORDER_DEF(rewind, void,
            (FILE* stream),
            (stream))
RECORDER_DEF(fgetpos, int,
            (FILE* stream, fpos_t* pos),
            (stream, pos))
RECORDER_DEF(fsetpos, int,
            (FILE* stream, const fpos_t* pos),
            (stream, pos))
RECORDER_DEF(fflush, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(feof, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(ferror, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(clearerr, void,
            (FILE* stream),
            (stream))
#endif
RECORDER_DEF(fileno, int,
            (FILE* stream),
            (stream))
RECORDER_DEF(fclose, int,
            (FILE* stream),
            (stream))
#if 0
RECORDER_DEF(fwprintf, int,
            (FILE* stream, const wchar_t* format, ...),
            (stream, format))
RECORDER_DEF(fwscanf, int,
            (FILE* stream, const wchar_t* format, ...),
            (stream, format))
RECORDER_DEF(vfwprintf, int,
            (FILE* stream, const wchar_t* format, va_list args),
            (stream, format, args))
RECORDER_DEF(vfwscanf, int,
            (FILE* stream, const wchar_t* format, va_list args),
            (stream, format, args))
RECORDER_DEF(fgetwc, wint_t,
            (FILE* stream),
            (stream))
RECORDER_DEF(fgetws, wchar_t*,
            (wchar_t* s, int n, FILE* stream),
            (s, n, stream))
RECORDER_DEF(fputwc, wint_t,
            (wchar_t wc, FILE* stream),
            (wc, stream))
RECORDER_DEF(fputws, int,
            (const wchar_t* s, FILE* stream),
            (s, stream))
RECORDER_DEF(fwide, int,
            (FILE* stream, int mode),
            (stream, mode))
RECORDER_DEF(getwc, wint_t,
            (FILE* stream),
            (stream))
RECORDER_DEF(putwc, wint_t,
            (wchar_t c, FILE* stream),
            (c, stream))
RECORDER_DEF(ungetwc, wint_t,
            (wint_t c, FILE* stream),
            (c, stream))

struct gotcha_binding_t unifyfs_wrappers[] = {
    { "access", RECORDER_WRAP(access), &wrappee_handle_access },
    { "chmod", RECORDER_WRAP(chmod), &wrappee_handle_chmod },
    { "mkdir", RECORDER_WRAP(mkdir), &wrappee_handle_mkdir },
    { "rmdir", RECORDER_WRAP(rmdir), &wrappee_handle_rmdir },
    { "chdir", RECORDER_WRAP(chdir), &wrappee_handle_chdir },
    { "__getcwd_chk", RECORDER_WRAP(__getcwd_chk),
        &wrappee_handle___getcwd_chk },
    { "getcwd", RECORDER_WRAP(getcwd), &wrappee_handle_getcwd },
    { "getwd", RECORDER_WRAP(getwd), &wrappee_handle_getwd },
    { "get_current_dir_name", RECORDER_WRAP(get_current_dir_name),
        &wrappee_handle_get_current_dir_name },
    { "rename", RECORDER_WRAP(rename), &wrappee_handle_rename },
    { "truncate", RECORDER_WRAP(truncate), &wrappee_handle_truncate },
    { "unlink", RECORDER_WRAP(unlink), &wrappee_handle_unlink },
    { "remove", RECORDER_WRAP(remove), &wrappee_handle_remove },
    { "stat", RECORDER_WRAP(stat), &wrappee_handle_stat },
    { "fstat", RECORDER_WRAP(fstat), &wrappee_handle_fstat },
    { "__xstat", RECORDER_WRAP(__xstat), &wrappee_handle___xstat },
    { "__fxstat", RECORDER_WRAP(__fxstat), &wrappee_handle___fxstat },
    { "__lxstat", RECORDER_WRAP(__lxstat), &wrappee_handle___lxstat },
    { "statfs", RECORDER_WRAP(statfs), &wrappee_handle_statfs },
    { "fstatfs", RECORDER_WRAP(fstatfs), &wrappee_handle_fstatfs },
    { "creat", RECORDER_WRAP(creat), &wrappee_handle_creat },
    { "creat64", RECORDER_WRAP(creat64), &wrappee_handle_creat64 },
    { "open", RECORDER_WRAP(open), &wrappee_handle_open },
    { "open64", RECORDER_WRAP(open64), &wrappee_handle_open64 },
    { "__open_2", RECORDER_WRAP(__open_2), &wrappee_handle___open_2 },
#ifdef HAVE_LIO_LISTIO
    { "lio_listio", RECORDER_WRAP(lio_listio), &wrappee_handle_lio_listio },
#endif
    { "lseek", RECORDER_WRAP(lseek), &wrappee_handle_lseek },
    { "lseek64", RECORDER_WRAP(lseek64), &wrappee_handle_lseek64 },
    { "posix_fadvise", RECORDER_WRAP(posix_fadvise), &wrappee_handle_posix_fadvise },
    { "read", RECORDER_WRAP(read), &wrappee_handle_read },
    { "write", RECORDER_WRAP(write), &wrappee_handle_write },
    { "readv", RECORDER_WRAP(readv), &wrappee_handle_readv },
    { "writev", RECORDER_WRAP(writev), &wrappee_handle_writev },
    { "pread", RECORDER_WRAP(pread), &wrappee_handle_pread },
    { "pread64", RECORDER_WRAP(pread64), &wrappee_handle_pread64 },
    { "pwrite", RECORDER_WRAP(pwrite), &wrappee_handle_pwrite },
    { "pwrite64", RECORDER_WRAP(pwrite64), &wrappee_handle_pwrite64 },
    { "fchdir", RECORDER_WRAP(fchdir), &wrappee_handle_fchdir },
    { "ftruncate", RECORDER_WRAP(ftruncate), &wrappee_handle_ftruncate },
    { "fsync", RECORDER_WRAP(fsync), &wrappee_handle_fsync },
    { "fdatasync", RECORDER_WRAP(fdatasync), &wrappee_handle_fdatasync },
    { "flock", RECORDER_WRAP(flock), &wrappee_handle_flock },
    { "fchmod", RECORDER_WRAP(fchmod), &wrappee_handle_fchmod },
    { "mmap", RECORDER_WRAP(mmap), &wrappee_handle_mmap },
    { "msync", RECORDER_WRAP(msync), &wrappee_handle_msync },
    { "munmap", RECORDER_WRAP(munmap), &wrappee_handle_munmap },
    { "mmap64", RECORDER_WRAP(mmap64), &wrappee_handle_mmap64 },
#endif
struct gotcha_binding_t recorder_wrappers[] = {
    { "PMPI_Init", PMPI_Init, &wrappee_handle_PMPI_Init },
    { "PMPI_Init_thread", PMPI_Init_thread, &wrappee_handle_PMPI_Init_thread },
    { "PMPI_Finalize", PMPI_Finalize, &wrappee_handle_PMPI_Finalize },
    { "access", RECORDER_POSIX_DECL(access), &wrappee_handle_access },
    { "mkdir", RECORDER_POSIX_DECL(mkdir), &wrappee_handle_mkdir },
    { "open", RECORDER_POSIX_DECL(open), &wrappee_handle_open },
    { "close", RECORDER_POSIX_DECL(close), &wrappee_handle_close },
    { "fopen", RECORDER_POSIX_DECL(fopen), &wrappee_handle_fopen },
    { "fclose", RECORDER_POSIX_DECL(fclose), &wrappee_handle_fclose },
    { "fwrite", RECORDER_POSIX_DECL(fwrite), &wrappee_handle_fwrite },
    { "remove", RECORDER_POSIX_DECL(remove), &wrappee_handle_remove },
    { "fileno", RECORDER_POSIX_DECL(fileno), &wrappee_handle_fileno },
};
#if 0
    { "opendir", RECORDER_WRAP(opendir), &wrappee_handle_opendir },
    { "fdopendir", RECORDER_WRAP(fdopendir), &wrappee_handle_fdopendir },
    { "closedir", RECORDER_WRAP(closedir), &wrappee_handle_closedir },
    { "readdir", RECORDER_WRAP(readdir), &wrappee_handle_readdir },
    { "rewinddir", RECORDER_WRAP(rewinddir), &wrappee_handle_rewinddir },
    { "dirfd", RECORDER_WRAP(dirfd), &wrappee_handle_dirfd },
    { "telldir", RECORDER_WRAP(telldir), &wrappee_handle_telldir },
    { "scandir", RECORDER_WRAP(scandir), &wrappee_handle_scandir },
    { "seekdir", RECORDER_WRAP(seekdir), &wrappee_handle_seekdir },
    { "fopen", RECORDER_WRAP(fopen), &wrappee_handle_fopen },
    { "freopen", RECORDER_WRAP(freopen), &wrappee_handle_freopen },
    { "setvbuf", RECORDER_WRAP(setvbuf), &wrappee_handle_setvbuf },
    { "setbuf", RECORDER_WRAP(setbuf), &wrappee_handle_setbuf },
    { "ungetc", RECORDER_WRAP(ungetc), &wrappee_handle_ungetc },
    { "fgetc", RECORDER_WRAP(fgetc), &wrappee_handle_fgetc },
    { "fputc", RECORDER_WRAP(fputc), &wrappee_handle_fputc },
    { "getc", RECORDER_WRAP(getc), &wrappee_handle_getc },
    { "putc", RECORDER_WRAP(putc), &wrappee_handle_putc },
    { "fgets", RECORDER_WRAP(fgets), &wrappee_handle_fgets },
    { "fputs", RECORDER_WRAP(fputs), &wrappee_handle_fputs },
    { "fread", RECORDER_WRAP(fread), &wrappee_handle_fread },
    { "fwrite", RECORDER_WRAP(fwrite), &wrappee_handle_fwrite },
    { "fprintf", RECORDER_WRAP(fprintf), &wrappee_handle_fprintf },
    { "vfprintf", RECORDER_WRAP(vfprintf), &wrappee_handle_vfprintf },
    { "fscanf", RECORDER_WRAP(fscanf), &wrappee_handle_fscanf },
    { "vfscanf", RECORDER_WRAP(vfscanf), &wrappee_handle_vfscanf },
    { "fseek", RECORDER_WRAP(fseek), &wrappee_handle_fseek },
    { "fseeko", RECORDER_WRAP(fseeko), &wrappee_handle_fseeko },
    { "ftell", RECORDER_WRAP(ftell), &wrappee_handle_ftell },
    { "ftello", RECORDER_WRAP(ftello), &wrappee_handle_ftello },
    { "rewind", RECORDER_WRAP(rewind), &wrappee_handle_rewind },
    { "fgetpos", RECORDER_WRAP(fgetpos), &wrappee_handle_fgetpos },
    { "fsetpos", RECORDER_WRAP(fsetpos), &wrappee_handle_fsetpos },
    { "fflush", RECORDER_WRAP(fflush), &wrappee_handle_fflush },
    { "feof", RECORDER_WRAP(feof), &wrappee_handle_feof },
    { "ferror", RECORDER_WRAP(ferror), &wrappee_handle_ferror },
    { "clearerr", RECORDER_WRAP(clearerr), &wrappee_handle_clearerr },
    { "fileno", RECORDER_WRAP(fileno), &wrappee_handle_fileno },
    { "fclose", RECORDER_WRAP(fclose), &wrappee_handle_fclose },
    { "fwprintf", RECORDER_WRAP(fwprintf), &wrappee_handle_fwprintf },
    { "fwscanf", RECORDER_WRAP(fwscanf), &wrappee_handle_fwscanf },
    { "vfwprintf", RECORDER_WRAP(vfwprintf), &wrappee_handle_vfwprintf },
    { "vfwscanf", RECORDER_WRAP(vfwscanf), &wrappee_handle_vfwscanf },
    { "fgetwc", RECORDER_WRAP(fgetwc), &wrappee_handle_fgetwc },
    { "fgetws", RECORDER_WRAP(fgetws), &wrappee_handle_fgetws },
    { "fputwc", RECORDER_WRAP(fputwc), &wrappee_handle_fputwc },
    { "fputws", RECORDER_WRAP(fputws), &wrappee_handle_fputws },
    { "fwide", RECORDER_WRAP(fwide), &wrappee_handle_fwide },
    { "getwc", RECORDER_WRAP(getwc), &wrappee_handle_getwc },
    { "putwc", RECORDER_WRAP(putwc), &wrappee_handle_putwc },
    { "ungetwc", RECORDER_WRAP(ungetwc), &wrappee_handle_ungetwc },
};
#endif

#define GOTCHA_NFUNCS (sizeof(recorder_wrappers) / sizeof(gotcha_binding_t))

int setup_gotcha_wrappers(void)
{
    /* insert our I/O wrappers using gotcha */
    enum gotcha_error_t result;
    result = gotcha_wrap(recorder_wrappers, GOTCHA_NFUNCS, "recorder");
    if (result != GOTCHA_SUCCESS) {
        printf("[GOTCHA] gotcha_wrap() returned %d", (int) result);
        if (result == GOTCHA_FUNCTION_NOT_FOUND) {
            /* one or more functions were not found */
            void* fn;
            gotcha_wrappee_handle_t* hdlptr;
            for (int i = 0; i < GOTCHA_NFUNCS; i++) {
                hdlptr = recorder_wrappers[i].function_handle;
                fn = gotcha_get_wrappee(*hdlptr);
                if (NULL == fn) {
                    printf("[GOTCHA ERROR] Failed to wrap function '%s'",
                            recorder_wrappers[i].name);
                }
            }
        } else {
            return -1;
        }
    }
    return 0;
}
