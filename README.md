<h1>
	minitalk (Unfinished)
</h1>
    
<p>
	<b>The purpose of this project is to code a small data exchange program using UNIX signals(´･ω･｀)</b><br>
</p>

<p align="center">
	
</p>

## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1. Common Instruction](#11-common-instruction)
    - [1.2. Project instructions](#12-project-instrucions)
    - [1.3. Mandatory part](#13-mandatory-part)
    - [1.4. Bonus part](#14-bonus-part)
2. [Error control](#2-error-control)
3. [Simple plan](#3-simple-plan)

## 1. Subject
### 1.1. Common Instruction
- Functions should not finish unexpectedly (segfault, bus error, double free, etc) or have undefined behaviour.
- All memory allocated on the heap shall be released appropriately when necessary. No memory leaks shall be allowed. 
- If the statement requires it, you must deliver a Makefile that will compile your source files to the required output with the -Wall, -Werror and -Wextra flags, and of course your Makefile must not relink.
- Your Makefile has to be included at least the norm $(NAME), all, clean, fclean and re.
- To deliver the bonus of your project you must include a bonus rule in your Makefile, in which you add all the headers, libraries or functions that are forbidden in the main part of the project. The bonus must be in separate_bonus. {c/h} files. The mandatory part and the bonus are evaluated separately.
- If your project allows the use of libft, you should copy its source and its associated Makefile into a libft directory with a corresponding Makefile. Your project's Makefile of your project should first compile the library using its Makefile, and then compile the project.
- It's recommended to create test programmes for your project, although this work will not be handed in or evaluated. It will give you the opportunity to verify that your software works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of your peers.
-　Submit your work to your assigned Git repository. Only work in your Git repository will be evaluated. If Deepthought evaluates your work, it will do so after your peers. If a bug is found during Deepthought's review, the review is over.

Who is Deepthought?

### 1.2.Project instructions
- Name your executable files "client" and "server".
- You have to turn in a Makefile which will compile your source files. It must not relink.
- You can definitely use your libft.
- You have to handle errors thoroughly. In no way your program should quit unexpectedly. (segmentation fault, bus error, double free, and so forth)
- Your program mustn't have memory leaks.
- You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.
- In order to complete the mandatory part, you are allowed to use the following functions:

    - write
    - ft_printf and any functions you coded
    - signal
    - sigemptyset
    - sigaddset
    - sigaction
    - kill
    - getpid
    - malloc
    - free
    - pause
    - sleep
    - usleep
    - exit
 
### 1.3. Mandatory part
クライアントとサーバーの形で通信プログラムを作成する必要がある。
- まずサーバーを起動する必要がある。起動後、PIDを出力しなければならない。
- クライアントは2つのパラメーターを受け取る：
    - サーバーのPID。
    - 送信する文字列。
- クライアントは、パラメータとして渡された文字列をサーバーに送信しなければならない。
文字列を受信したら、サーバーはそれを印刷しなければならない。
- サーバーは、かなり速く文字列を表示しなければならない。素早くというのは、もし時間がかかりすぎると思ったら、それは長すぎるということだろう。
```
100文字表示で1秒はかかりすぎ！
```

- サーバーは、再起動する必要なく、複数のクライアントから連続して文字列を受信できなければならない。
- クライアントとサーバーの間の通信は、UNIXのシグナルのみを使用して行う。
- 使用できるシグナルは、次の2つのみ： SIGUSR1 と SIGUSR2

```
Linuxシステムは、このタイプの保留中のシグナルがある場合、シグナルをキューに入れることはない！ボーナスタイム？
```
### 1.4. Bonus part
- サーバーは、受信したすべてのメッセージに対して、クライアントにシグナルを送り返すことで確認します。
- ユニコード文字に対応！

## 3. Error control
- Number of argument is not 2 (ac != 2)
- Different number of rows or columns
- Does it have to be enclosed by 0
    - No, it can be any numbers
- Numbers are not int(IDK)
- Shouldn't accept characters
- (How many numbers of rows or columns I have to accept?)


## 4. List of signals on linux

|Number|Name|Default Action|Description|
|-----|-----|-----|-----|
|1|SIGHUP|Terminate|Terminal line hangup or parent process terminated|
|2|SIGINT|Terminate|Interrupt from keyboard(ctrl-c)|
|3|SIGQUIT|Terminate|Quit from keyboard(ctrl-\)|
|4|SIGILL|Terminate|Illegal instruction|
|5|SIGTRAP|Core|Trace trap|
|6|SIGABRT|Core|Signal from abort function|
|7|SIGBUS|Terminate|Bus error|
|8|SIGFPE|Core|Floating-point exception|
|9|SIGKILL|Terminate|Kill program|
|10|SIGUSR1|Terminate|User-defined signal 1|
|11|SIGSEGV|Core|Invalid memory reference (segfault)|
|12|SIGUSER2|Terminate|User-defined signal 2|
|13|SIGPIPE|Terminate|Write in pipe with no reader|
|14|SIGALRM|Terminate|Timer signal from alarm function|
|15|SIGTERM|Terminate|Software termination signal|
|16|SIGSTKFLT|Terminate|Stack fault on coprocessor|
|17|SIGCHLD|Ignore|Child process has stopped or terminated|
|18|SIGCONT|Ignore|Continue process if stopped|
|19|SIGSTOP|Stop|Stop signal not from terminal|
|20|SIGTSTP|Stop|Stop signal from terminal(ctrl-z)|
|21|SIGTTIN|Stop|Background process read from terminal|
|22|SIGTTOU|Stop|Background process wrote to terminal|
|23|SIGURG|Ignore|Urgent condition on socket|
|24|SIGXCPU|Terminate|CPU time limit exceeded|
|25|SIGXFSZ|Terminate|File size limit exceeded|
|26|SIGVTALRM|Terminate|Virtual timer expired|
|27|SIGPROF|Terminate|Profiling timer expired|
|28|SIGWINCH|Ignore|Window size changed|
|29|SIGIO|Terminate|I/O now possible on a descriptor|
|30|SIGPWR|Terminate|Power failure|
|31|SIGSYS|Terminate|Bad system call|

- Accept argument (ac, **av(fd)) and pass to execve function
    - Error check(ac != 2)
    - pass to main function(fdf?)
        - gnl
            - error fail memory allocation (not necessary release memory)
            - error not numbers (necessary release memory)
            - error not int (necessary release memory)
            - pass to initiation (x, y and (general?))<- if it's needed
                - x = rows(列) - check all numbers of row, check the first row and the last row
                - y = columns(行) - check all numbers of columns, check the first columns and the last columns
                - general
            - pass to function draw (x, y, z, and colour)
                - x
                - y


## 5. Functions
### execve
execve () は、filename によって指定されたプログラムを実行する。 filename は、バイナリ実行形式か、"#! interpreter [arg]" という形式の行で始まるスクリプトでなければならない。 後者の場合、interpreter は適切な実行ファイルのパス名でなければならず、 それ自身がスクリプトであってはならない。そしてそれは interpreter [arg] filename の形で呼び出される。
argv は新しいプログラムに渡される引き数文字列の配列である。 envp は文字列の配列であり、伝統的に key=value の形式を しており、新しいプログラムの環境変数として渡される。 argv と envp の両方とも NULL ポインタで終っている 必要がある。引き数配列と環境変数は呼び出されたプログラムの main 関数を int main(int argc, char *argv[], char *envp[]) のように定義することによってアクセス可能になる。
成功した場合、execve () は返らない。 そして、呼び出し元のプロセスの text, data, bss, スタックは、 読み込まれたプログラムによって上書きされる。 呼び出されたプログラムは、呼び出し元の PID および exec 時クローズ (close-on-exec) の設定されていないすべての ファイル・ディスクリプタを継承する。 呼び出し元プロセスの保留シグナルは解除される。呼び出し元のプログラムで 設定されたシグナル捕獲時の動作はデフォルト動作に戻される。 SIGCHLD シグナルが SIG_IGN に設定されている場合は SIG_DFL にリセット されるかもしれないし、されないかもしれない。
もし元のプログラムが ptrace されていると、execve () が成功した後に そのプログラムに SIGTRAP が送られる。
filename で指定されたプログラムファイルに set-user-ID ビットが 設定されており、呼び出したプロセスが ptrace されていない場合、 呼び出したプロセスの実効 (effective) ユーザ ID は プログラムファイルの所有者 (owner) に変更される。 同様に、プログラムファイルに set-group-ID ビットが設定されていた場合、 呼び出したプロセスの有効グループ ID は プログラムファイルのグループに変更される。
プロセスの実効ユーザ ID は保存 (saved) set-user-ID にコピーされる。 同様に、実効グループ ID は保存 set-group-ID にコピーされる。 このコピーは、set-user-ID / set-group-ID 許可ビットにより発生する 実効 ID の変更後に行われる。
実行ファイルが動的リンクされた a.out 実行形式で、共有ライブラリの スタブを含むものだった場合、実行の開始時に Linux の ダイナミック・リンカ   ld.so (8) が呼び出され、必要な共有ライブラリをメモリに読み込んでリンクを行う。
実行ファイルがダイナミック・リンクされた ELF 実行形式だった場合、 PT_INTERP セグメントに指定されたインタプリタが必要な 共有ライブラリ (shared library) を読み込むのに使用される。 通常使用されるインタプリタは Linux libc version 5 をリンクしたバイナリ の場合には /lib/ld-linux.so.1 が、GNU libc version 2 をリンクした バイナリの場合には /lib/ld-linux.so.2 が使用される。

### fork
fork() は呼び出し元プロセスを複製して新しいプロセスを生成する。新しいプロセスは「子」プロセスと呼ばれ、呼び出し元プロセスは「親」プロセスと呼ばれる。
The child process and the parent process run in separate memory spaces. At the time of fork() both memory spaces have the same content. Memory writes, file mappings (mmap(2)), and unmappings (munmap(2)) performed by one of the processes do not affect the other.

The child process is an exact duplicate of the parent process except for the following points:

* The child has its own unique process ID, and this PID does not match the ID of any existing process group (setpgid(2)) or session.
* 子プロセスの親プロセス ID は、親プロセスのプロセス ID と同じb である。
* 子プロセスは親プロセスのメモリーロック (mlock(2), mlockall(2)) を引き継がない。
* プロセスの資源利用量 (getrusage(2)) と CPU タイムカウンター (times(2)) が、子プロセスでは 0 にリセットされる。
* 子プロセスの処理待ちのシグナルの集合 (sigpending(2)) は、初期状態では空になる。
* 子プロセスは親プロセスからセマフォ調整 (semop(2)) を引き継がない。
* 子プロセスは親プロセスからプロセスに関連付けられたレコードロックを引き継がない (fcntl(2))。 (一方、子プロセスは親プロセスから fcntl(2) オープンファイル記述ロックと flock(2) ロックを引き継ぐ。)
* 子プロセスは親プロセスからタイマー (setitimer(2), alarm(2), timer_create(2)) を引き継がない。
* 子プロセスは親プロセスから主だった非同期 I/O 操作を引き継がない (aio_read(3), aio_write(3) 参照)。 また、親プロセスから非同期 I/O コンテキストを引き継がない (io_setup(2) 参照)。
上記のリストにあるプロセス属性は、POSIX.1 で全て指定されている。 親プロセスと子プロセスは、以下の Linux 固有のプロセス属性も異なる:

* 子プロセスは親プロセスからディレクトリ変更通知 (dnotify) (fcntl(2) における F_NOTIFY の説明を参照) を引き継がない。
* prctl(2) の PR_SET_PDEATHSIG の設定がリセットされ、子プロセスは親プロセスが終了したときに シグナルを受信しない。
* timer slack value のデフォルト値には、親プロセスの現在の timer slack value が設定される。 prctl(2) の PR_SET_TIMERSLACK の説明を参照。
* madvise(2) の MADV_DONTFORK フラグでマークされたメモリーマッピングは、 fork() によって引き継がれない。
* Memory in address ranges that have been marked with the madvise(2) MADV_WIPEONFORK flag is zeroed in the child after a fork(). (The MADV_WIPEONFORK setting remains in place for those address ranges in the child.)
* 子プロセスの終了シグナルは常に SIGCHLD である (clone(2) を参照)。
* ioperm(2) で設定されるポートアクセス許可ビットは、子プロセスには継承されない。子プロセスでは、 ioperm(2) を使って必要なビットをセットしなければならない。
以下の点についても注意すること:

* 子プロセスはシングルスレッドで生成される。つまり、 fork() を呼び出したスレッドとなる。 親プロセスの仮想アドレス空間全体が子プロセスに複製される。 これにはミューテックス (mutex) の状態・条件変数・ pthread オブジェクトが含まれる。 これが引き起こす問題を扱うには、 pthread_atfork(3) を使うと良いだろう。
* After a fork() in a multithreaded program, the child can safely call only async-signal-safe functions (see signal-safety(7)) until such time as it calls execve(2).
* 子プロセスは親プロセスが持つ オープンファイルディスクリプターの集合のコピーを引き継ぐ。 子プロセスの各ファイルディスクリプターは、 親プロセスのファイルディスクリプターに対応する 同じオープンファイル記述 (file description) を参照する (open(2) を参照)。 これは 2 つのファイルディスクリプターが、ファイル状態フラグ・ ファイルオフセット、シグナル駆動 (signal-driven) I/O 属性 (fcntl(2) における F_SETOWN, F_SETSIG の説明を参照) を共有することを意味する。
* 子プロセスは親プロセスが持つオープンメッセージキューディスクリプター (mq_overview(7) を参照) の集合のコピーを引き継ぐ。 子プロセスの各ファイルディスクリプターは、 親プロセスのファイルディスクリプターに対応する同じオープンメッセージキューディスクリプターを参照する。 これは 2 つのファイルディスクリプターが同じフラグ (mq_flags) を共有することを意味する。
* 子プロセスは、親プロセスのオープン済みのディレクトリストリームの集合 (opendir(3) 参照) のコピーを継承する。 POSIX.1 では、親プロセスと子プロセス間の対応するディレクトリストリーム はディレクトリストリームの位置 (positioning) を共有してもよいとされている。 Linux/glibc ではディレクトリストリームの位置の共有は行われていない。