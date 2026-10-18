# 本リポジトリ上でのコード共有方法
本リポジトリ`Activity`上でのコード共有のルールについて記載する．

## `AtCoder/` でのコード共有方法
* ファイル名がユーザ間で重複しないよう，下記の命名規則に従ってリネームすること
  - 形式：`ABC<contest_number>_<problem_id>_<github_user_name>.cpp`
    - <contest_number>：コンテスト番号
    - <problem_id>：問題ID
    - <github_user_name>：GitHubユーザ名
  - 例）GitHub上のユーザ名が`usp`である人が作成したABC461のA問題の正解コードの場合，`ABC461_A_usp.cpp`
    - Pythonコードなら，`ABC461_A_usp.py`
* 下図のようなブランチ戦略で行う
  - ユーザ一人一人が独立したブランチ`feature/user-name`を作成し，そのブランチ上でコード共有を行う
  - `feature/user-name`から`dev/atcoder`ブランチにPull Request を作成し，ユーザ毎の Pull Request 上でコードレビューを行う
    - 識別しやすいように，**PR のタイトルは，ユーザ名を含めること**
    - 例）「ABCOOO (`user-name`)」
  - レビューを受けた後に，PRの`merge`を行う
```txt
<main>
  ▲
  │ Merge
  │
[Review]
  ▲
  │ PR
  │
<dev/atcoder>
  ▲
  │ Merge
  │
[Review]
  ▲
  ├──────── PR ─────── <feature/user001-name>
  ├──────── PR ─────── <feature/user002-name>
  ├──────── PR ─────── <feature/user003-name>
  ├──────── PR ─────── <feature/user004-name>
  └──────── PR ─────── <feature/user005-name>
                    ...

※ <branch-name> の形式でブランチ名を表す
```

<details><summary>以前のコード共有方法との比較</summary>  

* [以前手法] `dev/atcoder` ブランチ上で複数人のユーザがコード共有
  - 利点
    - PR の数が最低限で済む
  - 欠点
    - 複数人が`git push`を行うため，コンフリクトが発生しやすい
      - 発生するたびに，下記のような操作が必要で時間がかかる
        1. ローカル側で一旦自身のコミットを削除
        2. リモート側と同期をとる
        3. 再び自身の変更内容のコミットを登録
        4. `git push`を行う
      - また`push`が成功するかは早い者勝ち勝負になってしまい，ユーザの数が増えるほどコンフリクトが発生しやすくなる
    - コードレビューがしにくい
      - ユーザごとのコードレビューを行う際，全ユーザの共有ファイルが同一ブランチに集中するため，対象ファイルを探す時間が発生する

* [現在] `dev/atcoder`<-`feature/user-name` の形
  - 利点
    - 各ユーザが独立したブランチを持つため，コンフリクトが発生しない
    - ユーザごとのブランチからそれぞれPRを作成するため，コードレビューがしやすい
  - 欠点
    - 各ユーザの手間が増える
      - Pull Request を毎回作り，更に`merge`する手間が増える
      - PR を作る経験になると捉えれば，利点に

</details>
