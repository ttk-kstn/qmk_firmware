レイアウト試行錯誤

方針
 - 英語QWERTY配列をベースにする。
 - 数字列なしの配列への移行を目指す。
 - Vimでのコーディングでの使い易さを高める。

導入時の方針
 - 左右のスペースキーをシフトとしても使うように。いわゆるSandS。
 - スペースキーの外側にレイヤーキーを配置。
 - 左レイヤーキーのタップはVimでよく使う<kbd>ESC</kbd>。
 - 右レイヤーキーのタップは<kbd>Enter</kbd>。
 - 左右のレイヤーキーは論理的には別レイヤーだが、レイヤーキーに慣れるまでは同じ挙動にしておく。
 - 数字列をLRレイヤーに持ってくる。
   - シフトなしのキーコードを真下のQWER列に割り当て。(例:<kbd>Q</kbd>→<kbd>1</kbd>、<kbd>W</kbd>→<kbd>2</kbd>)
   - シフトありのキーコードをさらに下のZXCV列に割り当て。(例:<kbd>Z</kbd>→<kbd>!</kbd>、<kbd>X</kbd>→<kbd>@</kbd>)
 - カーソル移動関連をレイヤーのホーム列に割り当て。
   - <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> <kbd>F</kbd>に<kbd>Home</kbd> <kbd>End</kbd> <kbd>PageUp</kbd> <kbd>PageDown</kbd>
   - <kbd>H</kbd> <kbd>J</kbd> <kbd>K</kbd> <kbd>L</kbd>に<kbd>←</kbd> <kbd>↓</kbd> <kbd>↑</kbd> <kbd>→</kbd> (Vim)
   - <kbd>;</kbd> <kbd>:</kbd>に<kbd>BackSpace</kbd> <kbd>Delete</kbd>
 - スクリーンショット撮るのに使うので、右シフトの右に<kbd>PrtSc</kbd>

ちょっと慣れてきた時点での変更方針
 - Home-row modifierをやってみたくなった。
   - <kbd>A</kbd>と<kbd>;</kbd>を<kbd>Ctrl</kbd>にしてみた。<kbd>A</kbd>の横が<kbd>Ctrl</kbd>だったから。でも、ローマ字入力で暴発しやすい。<kbd>A</kbd>はダメ。
   - <kbd>S</kbd>と<kbd>L</kbd>を<kbd>Ctrl</kbd>にしてみる。
   - <kbd>F</kbd>と<kbd>J</kbd>を<kbd>Alt</kbd>にしてみた。
 - レイヤーキーに慣れてきたので左右の役割を変えてみる。
   - カーソル移動系は同じ側の手でレイヤーキーを押して使うことがほとんど。反対の手でレイヤーキーを押す場合は別のキーにできそう。
   - 数字列のキーをレイヤーでは下方向にあるキーにマッピングしたので、右上のキーほどつらくなった。しかも右上にはコーディングで頻出する-_=+|\\[]{}といったキーがある。
   - 右レイヤーキーを押した場合の<kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> <kbd>F</kbd> <kbd>G</kbd>に<kbd>~</kbd> <kbd>\\</kbd> <kbd>|</kbd> <kbd>_</kbd> <kbd>-</kbd>を割り当て。
   - 左レイヤーキーを押した場合の<kbd>H</kbd> <kbd>J</kbd> <kbd>K</kbd> <kbd>L</kbd>に<kbd>+</kbd> <kbd>=</kbd> <kbd>{</kbd> <kbd>}</kbd>を割り当て。
 - 左手片手で<kbd>Enter</kbd>を入力したいことがあるので、左レイヤーキー+<kbd>G</kbd>を<kbd>Enter</kbd>に。
 - 全然使わない親指列の右端キーで遊ぶ。
   - 1発で<kbd>Ctrl</kbd><kbd>Alt</kbd><kbd>Del</kbd>
   - Fレイヤーキーと一緒に押すと、keyboard-layout-editor.com のPermalinkを`SEND_STRING()`

その後の調整
 - ホームポジションにコーディングでよく使う記号があるのはとても便利。
   - なので、コーディングでよく使う<kbd>(</kbd>と<kbd>)</kbd>を<kbd>{</kbd>と<kbd>}</kbd>と入れ替え。
   - 遠いキー入力することはなくなったので、そっちは削除。
