package com.springbook.biz.board.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.springbook.biz.board.BoardService;
import com.springbook.biz.board.BoardVO;
// AOP �ǽ�
//import com.springbook.biz.common.LogAdvice;
// AOP �ǽ�
//import com.springbook.biz.common.Log4jAdvice;

@Service("boardService")
public class BoardServiceImpl implements BoardService {
	
	@Autowired
	private BoardDAO boardDAO;
	
	// Spring jdbc �ǽ�
	//@Autowired
	//private BoardDAOSpring boardDAO;
	// AOP �ǽ�
	//private Log4jAdvice log;
	
	/*
	public BoardServiceImpl() {
		log = new Log4jAdvice();
	}
	*/
	
	public void insertBoard(BoardVO vo) {
		// AOP �ǽ�
		// log.printLog();
		//log.printLogging();
		
		// After-Throwing �ǽ�
		/*
		if (vo.getSeq() == 0) {
			throw new IllegalArgumentException("0�� ���� ����� �� �����ϴ�.");
		}
		*/
		boardDAO.insertBoard(vo);
		// Transaction �ǽ�
		// ���� 100��° ���� ��� �����ϸ� �ι��� ���� insert�� Exception�� �߻��� ��
		// BOARD ���̺��� SEQ�� primary key�̹Ƿ� ���� �ǹǷ�
		// �̶� Ʈ������� �޼ҵ� ������ �����ǹǷ� �߻��� ���ܷ� ���� insertBoard() �޼ҵ��� �۾������ ��� �ѹ�(rollback) ó���ȴ�.
		//boardDAO.insertBoard(vo);
	}
	
	public void updateBoard(BoardVO vo) {
		// AOP �ǽ�
		// log.printLog();
		//log.printLogging();
		
		boardDAO.updateBoard(vo);
	}
	
	public void deleteBoard(BoardVO vo) {
		// AOP �ǽ�
		// log.printLog();
		//log.printLogging();
		
		boardDAO.deleteBoard(vo);
	}
	
	public BoardVO getBoard(BoardVO vo) {
		// AOP �ǽ�
		// log.printLog();
		//log.printLogging();
		
		return boardDAO.getBoard(vo);
	}
	
	public List<BoardVO> getBoardList(BoardVO vo) {
		// AOP �ǽ�
		// log.printLog();
		//log.printLogging();
		
		return boardDAO.getBoardList(vo);
	}

}
