/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2017 - 2018 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Файл ak_mac.h                                                                                  */
/*  - содержит описания функций, реализующих аутентифицированное шифрование
      и различные режимы его применения.                                                           */
/* ----------------------------------------------------------------------------------------------- */
#ifndef __AK_MGM_H__
#define __AK_MGM_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <ak_gf2n.h>
 #include <ak_bckey.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура, содержащая текущее состояние переменных аутентифицированного шифрования. */
 typedef struct mgm_ctx {
  /*! \brief Текущее значение имитовставки. */
   ak_uint128 sum;
  /*! \brief Счетчик, значения которого используются при шифровании информации. */
   ak_uint128 ycount;
  /*! \brief Счетчик, значения которого используются при выработке имитовставки. */
   ak_uint128 zcount;
  /*! \brief Размер обработанных зашифровываемых/расшифровываемых данных в битах. */
   ak_uint64 pbitlen;
  /*! \brief Размер обработанных дополнительных данных в битах. */
   ak_uint64 abitlen;
} *ak_mgm_ctx;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Секретный ключ алгоритма выработки имитовставки (режим аутентифицированного шифрования). */
 typedef struct mgm {
 /*! \brief Контекст секретного ключа аутентификации. */
  struct bckey bkey;
 /*! \brief Текущее состояние внутренних переменных алгоритма аутентифицированного шифрования. */
  struct mgm_ctx mctx;
} *ak_mgm;



#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                       ak_mgm.h  */
/* ----------------------------------------------------------------------------------------------- */
