package com.springbook.biz.board.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.springbook.biz.board.BoardService;
import com.springbook.biz.board.BoardVO;
// AOP 실습
//import com.springbook.biz.common.LogAdvice;
// AOP 실습
//import com.springbook.biz.common.Log4jAdvice;

@Service("boardService")
public class BoardServiceImpl implements BoardService {
	
	@Autowired
	private BoardDAO boardDAO;
	
	// Spring jdbc 실습
	//@Autowired
	//private BoardDAOSpring boardDAO;
	// AOP 실습
	//private Log4jAdvice log;
	
	/*
	public BoardServiceImpl() {
		log = new Log4jAdvice();
	}
	*/
	
	public void insertBoard(BoardVO vo) {
		// AOP 실습
		// log.printLog();
		//log.printLogging();
		
		// After-Throwing 실습
		/*
		if (vo.getSeq() == 0) {
			throw new IllegalArgumentException("0번 글은 등록할 수 없습니다.");
		}
		*/
		boardDAO.insertBoard(vo);
		// Transaction 실습
		// 만약 100번째 글이 등록 성공하면 두번쨰 오는 insert는 Exception이 발생될 것
		// BOARD 테이블의 SEQ가 primary key이므로 같게 되므로
		// 이때 트랜잭션을 메소드 단위로 관리되므로 발생한 예외로 인해 insertBoard() 메소드의 작업결과는 모두 롤백(rollback) 처리된다.
		//boardDAO.insertBoard(vo);
	}
	
	public void updateBoard(BoardVO vo) {
		// AOP 실습
		// log.printLog();
		//log.printLogging();
		
		boardDAO.updateBoard(vo);
	}
	
	public void deleteBoard(BoardVO vo) {
		// AOP 실습
		// log.printLog();
		//log.printLogging();
		
		boardDAO.deleteBoard(vo);
	}
	
	public BoardVO getBoard(BoardVO vo) {
		// AOP 실습
		// log.printLog();
		//log.printLogging();
		
		return boardDAO.getBoard(vo);
	}
	
	public List<BoardVO> getBoardList(BoardVO vo) {
		// AOP 실습
		// log.printLog();
		//log.printLogging();
		
		return boardDAO.getBoardList(vo);
	}

}
