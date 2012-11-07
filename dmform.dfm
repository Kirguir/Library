object DM: TDM
  OldCreateOrder = False
  Left = 406
  Top = 383
  Height = 298
  Width = 639
  object dsoLookup: TDataSource
    DataSet = dsLookup
    Left = 376
    Top = 16
  end
  object dsoOtdel: TDataSource
    DataSet = dsOtdel
    Left = 176
    Top = 8
  end
  object trsOtdel: TpFIBTransaction
    Active = True
    DefaultDatabase = dbOtdel
    TimeoutAction = TARollback
    Left = 88
    Top = 8
  end
  object truOtdel: TpFIBTransaction
    DefaultDatabase = dbOtdel
    TimeoutAction = TARollback
    Left = 128
    Top = 8
  end
  object dsOtdel: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE OTDEL'
      'SET '
      '    TVUZ = :TVUZ,'
      '    N_OTDEL = :N_OTDEL'
      'WHERE'
      '    KOD = :OLD_KOD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    OTDEL'
      'WHERE'
      '        KOD = :OLD_KOD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO OTDEL('
      '    KOD,'
      '    TVUZ,'
      '    N_OTDEL'
      ')'
      'VALUES('
      '    :KOD,'
      '    :TVUZ,'
      '    :N_OTDEL'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    O.KOD,    '
      '    O.TVUZ,'
      '    O.N_OTDEL'
      'FROM'
      '    OTDEL O'
      ''
      ' WHERE '
      '        O.KOD = :OLD_KOD'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    O.KOD,    '
      '    O.TVUZ,'
      '    O.N_OTDEL'
      'FROM'
      '    OTDEL O')
    AutoUpdateOptions.UpdateTableName = 'OTDEL'
    AutoUpdateOptions.KeyFields = 'KOD'
    AutoUpdateOptions.GeneratorName = 'OTD_NO_GEN'
    AutoUpdateOptions.WhenGetGenID = wgBeforePost
    Active = True
    AfterPost = dsOtdelAfterPost
    BeforeEdit = dsOtdelBeforeEdit
    BeforePost = dsOtdelBeforePost
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    AutoCommit = True
    Left = 48
    Top = 8
    object dsOtdelvuz: TStringField
      FieldKind = fkLookup
      FieldName = 'vuz'
      LookupDataSet = dsLookup
      LookupKeyFields = 'ID'
      LookupResultField = 'VUZ'
      KeyFields = 'TVUZ'
      Lookup = True
    end
    object dsOtdelKOD: TFIBIntegerField
      FieldName = 'KOD'
    end
    object dsOtdelTVUZ: TFIBIntegerField
      DefaultExpression = '1'
      FieldName = 'TVUZ'
    end
    object dsOtdelN_OTDEL: TFIBStringField
      FieldName = 'N_OTDEL'
      Size = 75
      EmptyStrToNull = True
    end
  end
  object dbOtdel: TpFIBDatabase
    Connected = True
    DBName = 'library/3050:librarydb'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=S0jkijzxc')
    DefaultTransaction = trsOtdel
    DefaultUpdateTransaction = truOtdel
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 8
    Top = 8
  end
  object dsPred: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE PREDMET'
      'SET '
      '    N_PREDMET = :N_PREDMET'
      'WHERE'
      '    KOD = :OLD_KOD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    PREDMET'
      'WHERE'
      '        KOD = :OLD_KOD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO PREDMET('
      '    KOD,'
      '    N_PREDMET'
      ')'
      'VALUES('
      '    :KOD,'
      '    :N_PREDMET'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    P.KOD,'
      '    P.N_PREDMET'
      'FROM'
      '    PREDMET P'
      ''
      ' WHERE '
      '        P.KOD = :OLD_KOD'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    P.KOD,'
      '    P.N_PREDMET'
      'FROM'
      '    PREDMET P'
      'ORDER BY N_PREDMET')
    AutoUpdateOptions.UpdateTableName = 'PREDMET'
    AutoUpdateOptions.KeyFields = 'KOD'
    AutoUpdateOptions.GeneratorName = 'PRED_NO_GEN'
    AutoUpdateOptions.WhenGetGenID = wgBeforePost
    Active = True
    AfterPost = dsPredAfterPost
    BeforeEdit = dsOtdelBeforeEdit
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    AutoCommit = True
    Left = 48
    Top = 64
  end
  object dsoPred: TDataSource
    DataSet = dsPred
    Left = 176
    Top = 64
  end
  object dsBook: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE BOOKS'
      'SET '
      '    F_AUTHOR = :F_AUTHOR,'
      '    N_AUTHOR = :N_AUTHOR,'
      '    T_AUTHOR = :T_AUTHOR,'
      '    BOOKNAME = :BOOKNAME,'
      '    TYPEBOOK = :TYPEBOOK,'
      '    BOOK     = :BOOK,'
      '    ABOUT    = :ABOUT'
      'WHERE'
      '    KOD = :OLD_KOD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    BOOKS'
      'WHERE'
      '        KOD = :OLD_KOD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO BOOKS('
      '    KOD,'
      '    F_AUTHOR,'
      '    N_AUTHOR,'
      '    T_AUTHOR,'
      '    BOOKNAME,'
      '    TYPEBOOK,'
      '    BOOK,'
      '    ABOUT'
      ')'
      'VALUES('
      '    :KOD,'
      '    :F_AUTHOR,'
      '    :N_AUTHOR,'
      '    :T_AUTHOR,'
      '    :BOOKNAME,'
      '    :TYPEBOOK,'
      '    :BOOK,'
      '    :ABOUT'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    B.KOD,'
      '    B.F_AUTHOR,'
      '    B.N_AUTHOR,'
      '    B.T_AUTHOR,'
      '    B.FULL_AUTHOR,'
      '    B.BOOKNAME,'
      '    B.TYPEBOOK,'
      '    B.BOOK,'
      '    B.ABOUT'
      'FROM'
      '    BOOKS B'
      ''
      ' WHERE '
      '        B.KOD = :OLD_KOD'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    B.KOD,'
      '    B.F_AUTHOR,'
      '    B.N_AUTHOR,'
      '    B.T_AUTHOR,'
      '    B.FULL_AUTHOR,'
      '    B.BOOKNAME,'
      '    B.TYPEBOOK,'
      '    B.BOOK,'
      '    B.ABOUT'
      'FROM'
      '    BOOKS B'
      'ORDER BY'
      '    B.F_AUTHOR')
    FilterOptions = [foCaseInsensitive]
    AutoUpdateOptions.UpdateTableName = 'BOOKS'
    AutoUpdateOptions.KeyFields = 'KOD'
    AutoUpdateOptions.GeneratorName = 'BOOK_NO_GEN'
    AutoUpdateOptions.WhenGetGenID = wgBeforePost
    Active = True
    AfterPost = dsBookAfterPost
    BeforeEdit = dsOtdelBeforeEdit
    BeforePost = dsBookBeforePost
    OnPostError = dsBookPostError
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    AutoCommit = True
    Filtered = True
    Left = 48
    Top = 112
    object dsBookKOD: TFIBIntegerField
      FieldName = 'KOD'
    end
    object dsBookF_AUTHOR: TFIBStringField
      FieldName = 'F_AUTHOR'
      Size = 15
      EmptyStrToNull = True
    end
    object dsBookN_AUTHOR: TFIBStringField
      FieldName = 'N_AUTHOR'
      Size = 1
      EmptyStrToNull = True
    end
    object dsBookT_AUTHOR: TFIBStringField
      FieldName = 'T_AUTHOR'
      Size = 1
      EmptyStrToNull = True
    end
    object dsBookFULL_AUTHOR: TFIBStringField
      FieldName = 'FULL_AUTHOR'
      EmptyStrToNull = True
    end
    object dsBookBOOKNAME: TFIBStringField
      FieldName = 'BOOKNAME'
      Size = 50
      EmptyStrToNull = True
    end
    object dsBookTYPEBOOK: TFIBIntegerField
      DefaultExpression = '1'
      FieldName = 'TYPEBOOK'
    end
    object dsBookBOOK: TFIBBlobField
      FieldName = 'BOOK'
      Size = 8
    end
    object dsBookABOUT: TFIBBlobField
      FieldName = 'ABOUT'
      Size = 8
    end
  end
  object dsoBook: TDataSource
    DataSet = dsBook
    Left = 176
    Top = 112
  end
  object dsoTree: TDataSource
    DataSet = dsTree
    Left = 176
    Top = 160
  end
  object dsTree: TpFIBDataSet
    UpdateSQL.Strings = (
      ''
      '    ')
    DeleteSQL.Strings = (
      '')
    InsertSQL.Strings = (
      '')
    RefreshSQL.Strings = (
      ''
      '    ')
    SelectSQL.Strings = (
      'select'
      '    s.id,'
      '    sp.kbook,'
      '    b.bookname,'
      '    b.full_author,'
      '    b.typebook,'
      '    b.about,'
      '    l.login'
      'from'
      '    spis2 s join spisbook sp on sp.id=s.id'
      '    join books b on sp.kbook=b.kod'
      '    join login l on sp.iduser=l.id'
      'ORDER BY'
      '    b.bookname')
    Filter = 'id=9999'
    Active = True
    BeforeEdit = dsOtdelBeforeEdit
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    Filtered = True
    Left = 48
    Top = 160
    object dsTreeID: TFIBIntegerField
      FieldName = 'ID'
    end
    object dsTreeBOOKNAME: TFIBStringField
      FieldName = 'BOOKNAME'
      Size = 50
      EmptyStrToNull = True
    end
    object dsTreeFULL_AUTHOR: TFIBStringField
      FieldName = 'FULL_AUTHOR'
      EmptyStrToNull = True
    end
    object dsTreeTYPEBOOK: TFIBIntegerField
      DefaultExpression = '1'
      FieldName = 'TYPEBOOK'
    end
    object dsTreeKBOOK: TFIBIntegerField
      FieldName = 'KBOOK'
    end
    object dsTreeABOUT: TFIBBlobField
      FieldName = 'ABOUT'
      Size = 8
    end
    object dsTreeLOGIN: TFIBStringField
      FieldName = 'LOGIN'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object dsLookup: TpFIBDataSet
    SelectSQL.Strings = (
      'SELECT *'
      'FROM'
      '    VUZ V')
    Active = True
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    Left = 320
    Top = 16
  end
  object dsoLookOtdel: TDataSource
    DataSet = dsLookOtdel
    Left = 376
    Top = 64
  end
  object dsLookOtdel: TpFIBDataSet
    SelectSQL.Strings = (
      'SELECT *'
      'FROM'
      '    otdel')
    Active = True
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    Left = 320
    Top = 64
  end
  object qInsert: TpFIBQuery
    Transaction = truOtdel
    Database = dbOtdel
    BeforeExecute = qInsertBeforeExecute
    Left = 320
    Top = 112
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object BookDlg: TOpenDialog
    Left = 576
    Top = 208
  end
  object dsSpis: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    s.id, '
      '    p.n_predmet,'
      '    s.kpred,'
      '    s.kotd,'
      '    s.kurs,'
      '    s.fobuch'
      'from'
      '    spis2 s join predmet p on s.kpred=p.kod'
      'ORDER BY'
      '    p.n_predmet')
    Active = True
    Transaction = trsOtdel
    Database = dbOtdel
    UpdateTransaction = truOtdel
    Filtered = True
    Left = 320
    Top = 160
    object dsSpisID: TFIBIntegerField
      FieldName = 'ID'
    end
    object dsSpisN_PREDMET: TFIBStringField
      FieldName = 'N_PREDMET'
      Size = 70
      EmptyStrToNull = True
    end
    object dsSpisKOTD: TFIBIntegerField
      FieldName = 'KOTD'
    end
    object dsSpisKURS: TFIBIntegerField
      FieldName = 'KURS'
    end
    object dsSpisFOBUCH: TFIBSmallIntField
      DefaultExpression = '1'
      FieldName = 'FOBUCH'
    end
    object dsSpisKPRED: TFIBIntegerField
      FieldName = 'KPRED'
    end
  end
  object DataSource1: TDataSource
    DataSet = dsSpis
    Left = 376
    Top = 160
  end
  object IBEvents1: TIBEvents
    AutoRegister = False
    Registered = False
    Left = 472
    Top = 40
  end
  object dsoLogin: TDataSource
    DataSet = dsLogin
    Left = 376
    Top = 216
  end
  object dsLogin: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from login')
    Active = True
    Transaction = trsOtdel
    Database = dbOtdel
    Left = 320
    Top = 216
  end
end
